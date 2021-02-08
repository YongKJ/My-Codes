# coding=gbk

import SpecifiedStart
import queue
import ChessBoard
import random
import copy
import SaveInfoToDB
import NoobRobot
import ForbidStep


class CentralControl(object):

    def __init__(self):
        self.Robot_gobang_type = 0  # 机器人的五子棋类型（黑棋或白棋）
        self.gobang_step_now = 0  # 此时轮到下棋的五子棋颜色
        self.Opening_type = 0  # 自由开局或指定开局
        self.free_start_forbid_choice = 0  # 自由开局是否启用禁手点判断
        self.free_three_change = 1  # 当玩家选择后手并且自由开局时，默认开启询问是否选择三手交换
        self.gobang_board = []  # 棋盘
        self.gobang_chess_total = 0  # 棋盘上棋子的总数
        self.round = 0  # 第几回（黑棋白棋各下一次为一回）
        self.Robot_input_stack = queue.LifoQueue()  # 机器人下棋堆栈
        self.Player_input_stack = queue.LifoQueue()  # 玩家下棋堆栈
        self.gobang_board_stack = queue.LifoQueue()  # 棋盘堆栈（悔棋专用）

        # 指定开局才需要初始化
        self.five_step_switch = False  # 是否选择五手N打
        self.five_step_num = 0  # 五手N打的数量
        self.three_step_change = False  # 是否三手交换
        self.specified_start_type = ""  # 斜指开局或直指开局
        self.specified_start_name = ""  # 26种指定开局中某棋局的名称
        self.specified_start_priority = []  # 26种指定开局中某棋局的优先级

    def gobang_board_quit(self):  # 退出
        Save = SaveInfoToDB.SaveInfoToDB()
        if self.Opening_type == 1:  # 五子棋信息保存到数据库
            Save.Save_regular_start_info_to_db(self.Robot_gobang_type, self.Opening_type, self.five_step_switch,
                                               self.five_step_num, self.three_step_change, self.specified_start_type,
                                               self.specified_start_name, self.specified_start_priority,
                                               self.Robot_input_stack, self.Player_input_stack, self.gobang_board_stack)
        else:
            Save.Save_free_start_info_to_db(self.Robot_gobang_type, self.Opening_type, self.Robot_input_stack,
                                            self.Player_input_stack, self.gobang_board_stack)
        exit()

    def gobang_board_undo(self):  # 悔棋
        self.gobang_chess_total -= 2  # 棋盘上棋子的总数减二
        # 操作堆栈
        self.Robot_input_stack.get()
        self.Player_input_stack.get()
        for i in range(2):
            self.gobang_board_stack.get()
        self.gobang_board = self.gobang_board_stack.get()
        self.gobang_board_stack.put(copy.deepcopy(self.gobang_board))

    def show_the_gobang_board_now(self, board):  # 显示此时的棋盘矩阵
        self.update_round()
        UI = ChessBoard.ChessBoard()
        UI.out_gobang_board(self.round, board)

    def update_round(self):  # 更新第几轮
        if self.gobang_chess_total % 2 == 1:
            self.round = self.gobang_chess_total // 2 + 1
        else:
            self.round = self.gobang_chess_total // 2

    def gobang_type_choose(self):  # 选择先后手
        print("请选择先手或者后手(输入B选择先手，输入W选择后手):")
        gobang_type = input()
        if gobang_type.upper() == "B":
            self.Robot_gobang_type = 2
        else:
            self.Robot_gobang_type = 1

    def free_gobang_start_init(self):  # 自由开局初始化
        self.Opening_type = 2  # 自由开局
        self.round = 1  # 第一轮

        if self.Robot_gobang_type == 1:  # 玩家旋转后手
            self.gobang_step_now = 2  # 轮到玩家下棋
            self.gobang_board = [[0 for n in range(15)] for m in range(15)]  # 棋盘矩阵初始化
            self.gobang_board[7][7] = 1  # 菜鸟机器人下先手第一个黑棋
            self.gobang_chess_total = 1  # 棋盘上棋子总数为1
            step_list = [7, 7]
            self.stack_push(step_list)  # 棋子坐标入栈
        else:  # 玩家旋转先手
            self.gobang_step_now = 1  # 轮到玩家下棋
            self.gobang_board = [[0 for n in range(15)] for m in range(15)]  # 棋盘矩阵初始化
            self.gobang_chess_total = 0  # 棋盘上棋子总数为0

        self.show_the_gobang_board_now(self.gobang_board)  # 显示此时的棋盘矩阵

    def regular_gobang_start_init(self):  # 指定开局初始化
        self.Opening_type = 1  # 指定开局
        self.round = 2  # 第二轮
        self.gobang_chess_total = 3  # 棋盘上棋子总数为3
        specified_start = SpecifiedStart.SpecifiedStart()

        print("请选择是否需要五手N打(输入Y/N):")  # 是否选择初始化五手N打
        five_step_switch_str = input()
        if five_step_switch_str.upper() == "Y":
            self.five_step_switch = True  # 选择五手N打

        if self.Robot_gobang_type == 1:  # 当机器人选择黑棋时的初始化
            self.gobang_step_now = 2  # 轮到下白棋
            if self.five_step_switch:
                self.five_step_num = random.randint(2, 5)  # 随机生成五手N打的数量
                print("菜鸟机器人选择的五手N打的数量为%d" % self.five_step_num)
            self.gobang_board = specified_start.random_read_db()  # 随机生成直接开局中的棋盘矩阵
        else:  # 当机器人选择白棋时的初始化
            self.gobang_step_now = 2  # 轮到下白棋
            if self.five_step_switch:
                print("请选择五手N打数量的生成方式(输入A选择自动生成，输入H选择手动生成):")  # 五手N打初始化
                choose_type = input()
                if choose_type.upper().upper() == "A":
                    self.five_step_num = random.randint(2, 5)  # 随机生成五手N打的数量
                    print("随机生成的五手N打数量为%d" % self.five_step_num)
                else:
                    print("请输入五手N打的数量(请输入一个整数):")
                    self.five_step_num = int(input())  # 手动输入五手N打的数量

            print("请选择开局的生成方式(输入A选择自动生成，输入H选择手动生成):")  # 指定开局类型初始化
            specified_start_type = input()
            if specified_start_type.upper() == "A":
                self.gobang_board = specified_start.random_read_db()  # 随机生成26中指定开局中的一种
            else:
                self.gobang_board = specified_start.hand_read_db()  # 手动选择26中指定开局中的一种

        if specified_start.get_start_type() == "inclined":  # 棋局信息初始化
            self.specified_start_type = "斜指开局"
        else:
            self.specified_start_type = "直指开局"
        self.specified_start_name = specified_start.get_start_name()  # 获得指定开局名称
        self.specified_start_priority = specified_start.get_priority()  # 获得指定开局优先级

        self.gobang_board_stack.put(copy.deepcopy(self.gobang_board))  # 棋盘矩阵入栈
        print(self.specified_start_type + ":" + self.specified_start_name + "局")
        self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵

    def opening_type_choose(self):  # 选择开局方式
        print("请选择开局方式(输入R选择指定开局，输入F选择自由开局):")
        opening_type = input()
        if opening_type.upper().upper() == "F":
            print("请选择是否启用禁手点判断(输入Y/N):")
            choice = input()  # 选择是否开启禁手点判断
            if choice.upper() == "Y":
                self.free_start_forbid_choice = 1
            self.free_gobang_start_init()  # 调用自由开局初始化函数
        else:
            self.regular_gobang_start_init()  # 调用指定开局初始化函数

    def get(self, row, col):  # 返回当前位置的棋子
        if row < 0 or row >= 15 or col < 0 or col >= 15:
            return 0
        return self.gobang_board[row][col]

    # 判断输赢，返回0（无输赢），1（白棋赢），2（黑棋赢）
    def check(self):
        board = self.gobang_board
        dirs = ((1, -1), (1, 0), (1, 1), (0, 1))  # 四个方向，左斜，垂直，右斜，水平
        for i in range(15):
            for j in range(15):
                if board[i][j] == 0:
                    continue
                id = board[i][j]  # 标记棋子颜色
                for d in dirs:  # 遍历四个方向
                    x, y = j, i
                    count = 0
                    for k in range(5):
                        if self.get(y, x) != id:  # 计数，是否构成5个同色棋子连在一起
                            break
                        y += d[0]
                        x += d[1]
                        count += 1
                    if count == 5:
                        self.won = {}
                        r, c = i, j
                        for z in range(5):  # 连在一起的5个同色棋子的坐标入won队列
                            self.won[(r, c)] = 1
                        r += d[0]
                        c += d[1]
                    return id

        return 0

    def player_move(self):  # 玩家移动棋子
        if self.Opening_type == 1 and self.gobang_chess_total == 4:
            self.deal_five_step()  # 指定开局，并且棋盘上有4个棋子时开始进入五手N打函数

        if self.Opening_type == 2 and self.gobang_chess_total == 3 and self.gobang_step_now == 2 and self.free_three_change == 1:
            print("请选择是否三手交换(输入Y/N)：")
            choose = input()  # 自由开局，棋盘上有3个棋子，此时轮到下白棋，自由开局的三手交换选择标记为一
            if choose.upper() == "Y":
                self.Robot_gobang_type = 2  # 三手交换后，玩家由后手变为先手
                self.robot_move()  # 轮到菜鸟机器人下白棋
            else:
                self.free_three_change = 0  # 玩家没有进行三手交换，将标记置为0，则下次不再询问玩家是否选择三手交换
                self.player_move()  # 轮到玩家下白棋

        player_input = input("请输入你想移动的位置(U:悔棋, Q:退出):")  # 玩家输入下棋的坐标
        if len(player_input) == 2:  # 玩家是否输入由两个字母构成的坐标
            x = ord(player_input[0].upper()) - ord("A")  # 转换坐标
            y = ord(player_input[1].upper()) - ord("A")
            if self.gobang_step_now == 1:  # 此时下黑棋
                if 0 < x < 15 and 0 < y < 15:  # 坐标是否合法
                    if self.gobang_board[x][y] == 0:  # 判断当前坐标是否为空
                        self.gobang_board[x][y] = 1  # 标记为黑棋
                    else:  # 当前坐标不为空
                        print("不能移动到这里")
                        self.player_move()  # 玩家重新输入坐标
                        return 0
                else:  # 坐标不合法
                    print("超出边界")
                    self.player_move()  # 玩家重新输入坐标
                    return 0
                if self.check() == 1:  # 判断黑棋是否构成五连
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    print("恭喜了！你赢了！")
                    self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
                elif self.check() == 2:  # 判断白棋是否构成五连
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    print("很遗憾！你输了！")
                    self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
                elif self.check() == 0 and self.gobang_chess_total == 225:  # 判断是否和棋
                    print("WOW!和棋啦！")
                    self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
                self.gobang_step_now = 2  # 轮到下白棋
            else:  # 此时下白棋
                if 0 < x < 15 and 0 < y < 15:  # 坐标是否合法
                    if self.gobang_board[x][y] == 0:  # 判断当前坐标是否为空
                        self.gobang_board[x][y] = 2  # 标记为白棋
                    else:  # 当前坐标不为空
                        print("不能移动到这里")
                        self.player_move()  # 玩家重新输入坐标
                        return 0
                else:  # 坐标不合法
                    print("超出边界")
                    self.player_move()  # 玩家重新输入坐标
                    return 0
                if self.check() == 2:  # 判断白棋是否构成五连
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    print("恭喜了！你赢了！")
                    self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
                elif self.check() == 1:  # 判断黑棋是否构成五连
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    print("很遗憾！你输了！")
                    self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
                elif self.check() == 0 and self.gobang_chess_total == 225:  # 判断是否和棋
                    print("WOW!和棋啦！")
                    self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
                self.gobang_step_now = 1  # 轮到下黑棋
            player_move_list = [x, y]
            self.stack_push(player_move_list)  # 坐标入栈
            self.gobang_chess_total += 1  # 棋盘上棋子总数加1
        elif player_input.upper() == "U":  # 玩家输入大写字母U进行悔棋操作
            if self.Opening_type == 2:  # 是否自由开局
                if self.round < 3:  # 小于3轮不得悔棋
                    print("\n指定开局的下棋回合低于3回，不允许悔棋！")
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    self.player_move()  # 玩家重新输入
                else:
                    self.gobang_board_undo()  # 悔棋
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    self.player_move()  # 悔棋后重新轮到玩家输入
            else:  # 指定开局
                if self.round < 5:  # 小于5轮不得悔棋
                    print("\n指定开局的下棋回合低于5回，不允许悔棋！")
                    self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                    self.player_move()  # 玩家重新输入
                else:
                    self.gobang_board_undo()  # 悔棋
        else:  # 玩家输入字母Q进行退出操作
            self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
        self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
        self.robot_move()  # 轮到菜鸟机器人下棋

    def robot_move(self):  # 机器人移动棋子
        if self.Opening_type == 1 and self.gobang_chess_total == 4:
            self.deal_five_step()  # 指定开局，并且棋盘上有4个棋子时开始进入五手N打函数

        print("菜鸟机器人正在思考...")
        noobrobot = NoobRobot.NoobRobot()  # 菜鸟机器人初始化

        DEPTH = 3  # 博弈树深度初始化

        noobrobot.board = self.gobang_board  # 菜鸟机器人的棋盘矩阵初始化
        noobrobot.Opening_type = self.Opening_type  # 菜鸟机器人的开局类型矩阵初始化
        score, row, col = noobrobot.search(self.gobang_step_now, DEPTH)  # 获得最好棋盘评分和最佳移动位置坐标
        x = chr(ord("A") + row)
        y = chr(ord("A") + col)

        out_str = ""
        out_str += "菜鸟机器人移动到  " + x + y + " (" + str(score) + ")"
        print(out_str)

        if self.gobang_step_now == 1:  # 此时是否下黑棋
            self.gobang_board[row][col] = 1  # 标记为黑棋
            if self.check() == 1:  # 判断黑棋是否构成五连
                self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                print("很遗憾！你输了！")
                self.gobang_board_quit()
            elif self.check() == 2:  # 判断白棋是否构成五连
                self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                print("恭喜了！你赢了！")
                self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
            elif self.check() == 0 and self.gobang_chess_total == 225:  # 判断是否和棋
                print("WOW!和棋啦！")
                self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
            self.gobang_step_now = 2  # 轮到下白棋
        else:  # 此时下白棋
            self.gobang_board[row][col] = 2  # 标记为白棋
            if self.Opening_type == 1:  # 指定开局
                self.check_forbid_step()  # 禁手点判断
            if self.free_start_forbid_choice == 1:  # 自由开局禁手点表示为1则进行禁手点判断
                self.check_forbid_step()  # 禁手点判断
            if self.check() == 2:  # 判断白棋是否构成五连
                self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                print("很遗憾！你输了！")
                self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
            elif self.check() == 1:  # 判断黑棋是否构成五连
                self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
                print("恭喜了！你赢了！")
                self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
            elif self.check() == 0 and self.gobang_chess_total == 225:  # 判断是否和棋
                print("WOW!和棋啦！")
                self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
            self.gobang_step_now = 1  # 轮到下黑棋

        robot_move_list = [row, col]
        self.stack_push(robot_move_list)  # 坐标入栈
        self.gobang_chess_total += 1  # 棋盘上棋子总数加1

        self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
        self.player_move()  # 轮到玩家下棋

    def stack_push(self, move_input):  # 机器人，玩家下的棋以及当前棋局入栈
        if self.gobang_step_now != self.Robot_gobang_type:  # 此时下的棋不是菜鸟机器人选择的棋子类型
            self.Robot_input_stack.put(copy.deepcopy(move_input))  # 菜鸟机器人下棋坐标入栈
        else:  # 此时下的棋不是玩家选择的棋子类型
            self.Player_input_stack.put(copy.deepcopy(move_input))  # 玩家下棋坐标入栈
        self.gobang_board_stack.put(copy.deepcopy(self.gobang_board))  # 棋盘矩阵入栈

    def deal_five_step(self):  # 五手N打
        noobrobot = NoobRobot.NoobRobot()  # 菜鸟机器人初始化
        noobrobot.board = self.gobang_board  # 菜鸟机器人的棋盘矩阵初始化

        if self.Robot_gobang_type == 1:  # 此时菜鸟机器人是否为先手
            pos = noobrobot.deal_robot_five_step(self.five_step_num, self.gobang_step_now)  # 获得菜鸟机器人选择的五手N打的位置坐标POS队列
            num = 1  # 输出位置坐标POS队列
            out_str = ""
            for i, j in pos:
                x = chr(ord("A") + i)
                y = chr(ord("A") + j)
                out_str += str(num) + "." + x + y
                if num == self.five_step_num:
                    out_str += "\n"
                else:
                    out_str += " "
                num += 1
            out_str += "\n" + "请选择菜鸟机器人的五手" + str(self.five_step_num) + "打移动位置的编号:"
            print(out_str)
            pos_num = int(input())  # 玩家从POS队列中选择合适的位置坐标
            row, col = pos[pos_num - 1]
            self.gobang_board[row][col] = 1  # 标记为黑棋
            self.gobang_step_now = 2  # 轮到下白棋

            robot_move_list = [row, col]
            self.stack_push(robot_move_list)  # 坐标入栈
            self.gobang_chess_total += 1  # 棋盘上棋子总数加1

            self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
            self.player_move()  # 轮到玩家下棋
        else:  # 此时玩家为先手
            print("请输入你的五手%d打(输入一行数据，空格隔开)：" % self.five_step_num)
            pos = []
            pos = input().split()  # 玩家输入五手N打的位置坐标
            moves = []
            if len(pos) != self.five_step_num:  # 判断位置坐标数量是否足够
                print("请检查你输入的五手%d打的移动位置数量合理，请重新输入！")
                self.deal_five_step()  # 重新输入
                return 0
            for i in range(self.five_step_num):
                x = ord(pos[i][0].upper()) - ord("A")
                y = ord(pos[i][1].upper()) - ord("A")
                if 0 <= x <= 14 and 0 <= y <= 14:  # 判断坐标是否合法
                    if self.gobang_board[x][y] == 0:  # 判断坐标是否为空
                        moves.append((x, y))  # 坐标入moves队列
                    else:  # 坐标不为空
                        print("请检查你输入的棋子移动位置，重新输入！")
                        self.deal_five_step()  # 重新输入
                        return 0
                else:  # 坐标位置不合法
                    print("你输入的棋子移动位置有错误，请重新输入！")
                    self.deal_five_step()  # 重新输入
                    return 0
            row, col = noobrobot.deal_player_five_step(moves, self.gobang_step_now)  # 处理玩家输入的五手N打moves队列
            x = chr(ord("A") + row)
            y = chr(ord("A") + col)
            s = ""
            s += x + y
            print("菜鸟机器人选择你的五手%d打的移动位置为 (%s)" % (self.five_step_num, s))
            self.gobang_board[row][col] = 1  # 标记为黑棋
            self.gobang_step_now = 2  # 轮到下白棋

            player_move_list = [row, col]
            self.stack_push(player_move_list)  # 坐标入栈
            self.gobang_chess_total += 1  # 棋盘上棋子总数加1

            self.show_the_gobang_board_now(self.gobang_board)  # 显示棋盘矩阵
            self.robot_move()  # 轮到菜鸟机器人下棋

    def check_forbid_step(self):  # 禁手点的判断，包括三三禁手，四四禁手，长连禁手
        CheckStep = ForbidStep.ForbidStep()
        CheckStep.board = self.gobang_board  # 用于判断禁手点的棋盘矩阵初始化
        for i in range(15):
            for j in range(15):
                if self.gobang_board[i][j] == 1:  # 判断是否为黑棋
                    if CheckStep.charge_three_forbid(i, j):  # 判断是否为三三禁手点
                        row = chr(ord("A") + i)
                        col = chr(ord("A") + j)
                        s = ""
                        s += row + col
                        print("很不幸啊，你踩中了地雷般的禁手点！你踩中的三三禁手点为 (%s) ，你输了！" % (s))
                        self.gobang_board_quit()  # 将棋盘信息存入数据库并退出

                    if CheckStep.charge_four_forbid(i, j):  # 判断是否为四四禁手
                        row = chr(ord("A") + i)
                        col = chr(ord("A") + j)
                        s = ""
                        s += row + col
                        print("很不幸啊，你踩中了地雷般的禁手点！你踩中的四四禁手点为 (%s) ，你输了！" % (s))
                        self.gobang_board_quit()  # 将棋盘信息存入数据库并退出

                    if CheckStep.charge_long_forbid(i, j):  # 判断是否为长连禁手
                        row = chr(ord("A") + i)
                        col = chr(ord("A") + j)
                        s = ""
                        s += row + col
                        print("很不幸啊，你踩中了地雷般的禁手点！你踩中的长连禁手点为 (%s) ，你输了！" % (s))
                        self.gobang_board_quit()  # 将棋盘信息存入数据库并退出
        return 0

    def gobang_go(self):  # 棋局初始化后开始下棋
        if self.Robot_gobang_type == 1 and self.Opening_type == 1:  # 菜鸟机器人是否为先手并且开局类型为指定开局
            print("请选择是否三手交换(输入Y/N)：")
            choose = input()  # 玩家输入是否三手交换
            if choose.upper() == "Y":
                self.Robot_gobang_type = 2  # 菜鸟机器人变为后手
                self.robot_move()  # 轮到菜鸟机器人下棋
            else:  # 玩家不选择三手交换
                self.player_move()  # 轮到玩家下棋
        elif self.Robot_gobang_type == 2 and self.Opening_type == 1:  # 菜鸟机器人是否为后手并且开局类型为指定开局
            print("菜鸟机器人思考是否三手交换...")
            if self.specified_start_priority[0] == "1":  # 判断指定开局中的棋局优先级是否为黑棋优先
                print("菜鸟机器人选择交换先后手")
                self.Robot_gobang_type = 1  # 菜鸟机器人变为先手
                self.player_move()  # 轮到玩家下棋
            else:  # 指定开局中的棋局优先级为白棋优先
                print("菜鸟机器人决定不交换先后手")
                self.robot_move()  # 轮到菜鸟机器人下棋
        elif self.Robot_gobang_type == 1 and self.Opening_type == 2:  # 菜鸟机器人是否为先手并且开局类型为自由开局
            self.player_move()  # 轮到玩家下棋
        elif self.Robot_gobang_type == 2 and self.Opening_type == 2:  # 菜鸟机器人是否为后手并且开局类型为自由开局
            self.player_move()  # 轮到玩家下棋


if __name__ == "__main__":
    s = CentralControl()
    s.gobang_type_choose()
    s.opening_type_choose()
    s.gobang_go()
