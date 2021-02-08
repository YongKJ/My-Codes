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
        self.Robot_gobang_type = 0  # �����˵����������ͣ��������壩
        self.gobang_step_now = 0  # ��ʱ�ֵ��������������ɫ
        self.Opening_type = 0  # ���ɿ��ֻ�ָ������
        self.free_start_forbid_choice = 0  # ���ɿ����Ƿ����ý��ֵ��ж�
        self.free_three_change = 1  # �����ѡ����ֲ������ɿ���ʱ��Ĭ�Ͽ���ѯ���Ƿ�ѡ�����ֽ���
        self.gobang_board = []  # ����
        self.gobang_chess_total = 0  # ���������ӵ�����
        self.round = 0  # �ڼ��أ�����������һ��Ϊһ�أ�
        self.Robot_input_stack = queue.LifoQueue()  # �����������ջ
        self.Player_input_stack = queue.LifoQueue()  # ��������ջ
        self.gobang_board_stack = queue.LifoQueue()  # ���̶�ջ������ר�ã�

        # ָ�����ֲ���Ҫ��ʼ��
        self.five_step_switch = False  # �Ƿ�ѡ������N��
        self.five_step_num = 0  # ����N�������
        self.three_step_change = False  # �Ƿ����ֽ���
        self.specified_start_type = ""  # бָ���ֻ�ֱָ����
        self.specified_start_name = ""  # 26��ָ��������ĳ��ֵ�����
        self.specified_start_priority = []  # 26��ָ��������ĳ��ֵ����ȼ�

    def gobang_board_quit(self):  # �˳�
        Save = SaveInfoToDB.SaveInfoToDB()
        if self.Opening_type == 1:  # ��������Ϣ���浽���ݿ�
            Save.Save_regular_start_info_to_db(self.Robot_gobang_type, self.Opening_type, self.five_step_switch,
                                               self.five_step_num, self.three_step_change, self.specified_start_type,
                                               self.specified_start_name, self.specified_start_priority,
                                               self.Robot_input_stack, self.Player_input_stack, self.gobang_board_stack)
        else:
            Save.Save_free_start_info_to_db(self.Robot_gobang_type, self.Opening_type, self.Robot_input_stack,
                                            self.Player_input_stack, self.gobang_board_stack)
        exit()

    def gobang_board_undo(self):  # ����
        self.gobang_chess_total -= 2  # ���������ӵ���������
        # ������ջ
        self.Robot_input_stack.get()
        self.Player_input_stack.get()
        for i in range(2):
            self.gobang_board_stack.get()
        self.gobang_board = self.gobang_board_stack.get()
        self.gobang_board_stack.put(copy.deepcopy(self.gobang_board))

    def show_the_gobang_board_now(self, board):  # ��ʾ��ʱ�����̾���
        self.update_round()
        UI = ChessBoard.ChessBoard()
        UI.out_gobang_board(self.round, board)

    def update_round(self):  # ���µڼ���
        if self.gobang_chess_total % 2 == 1:
            self.round = self.gobang_chess_total // 2 + 1
        else:
            self.round = self.gobang_chess_total // 2

    def gobang_type_choose(self):  # ѡ���Ⱥ���
        print("��ѡ�����ֻ��ߺ���(����Bѡ�����֣�����Wѡ�����):")
        gobang_type = input()
        if gobang_type.upper() == "B":
            self.Robot_gobang_type = 2
        else:
            self.Robot_gobang_type = 1

    def free_gobang_start_init(self):  # ���ɿ��ֳ�ʼ��
        self.Opening_type = 2  # ���ɿ���
        self.round = 1  # ��һ��

        if self.Robot_gobang_type == 1:  # �����ת����
            self.gobang_step_now = 2  # �ֵ��������
            self.gobang_board = [[0 for n in range(15)] for m in range(15)]  # ���̾����ʼ��
            self.gobang_board[7][7] = 1  # ��������������ֵ�һ������
            self.gobang_chess_total = 1  # ��������������Ϊ1
            step_list = [7, 7]
            self.stack_push(step_list)  # ����������ջ
        else:  # �����ת����
            self.gobang_step_now = 1  # �ֵ��������
            self.gobang_board = [[0 for n in range(15)] for m in range(15)]  # ���̾����ʼ��
            self.gobang_chess_total = 0  # ��������������Ϊ0

        self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ��ʱ�����̾���

    def regular_gobang_start_init(self):  # ָ�����ֳ�ʼ��
        self.Opening_type = 1  # ָ������
        self.round = 2  # �ڶ���
        self.gobang_chess_total = 3  # ��������������Ϊ3
        specified_start = SpecifiedStart.SpecifiedStart()

        print("��ѡ���Ƿ���Ҫ����N��(����Y/N):")  # �Ƿ�ѡ���ʼ������N��
        five_step_switch_str = input()
        if five_step_switch_str.upper() == "Y":
            self.five_step_switch = True  # ѡ������N��

        if self.Robot_gobang_type == 1:  # ��������ѡ�����ʱ�ĳ�ʼ��
            self.gobang_step_now = 2  # �ֵ��°���
            if self.five_step_switch:
                self.five_step_num = random.randint(2, 5)  # �����������N�������
                print("���������ѡ�������N�������Ϊ%d" % self.five_step_num)
            self.gobang_board = specified_start.random_read_db()  # �������ֱ�ӿ����е����̾���
        else:  # ��������ѡ�����ʱ�ĳ�ʼ��
            self.gobang_step_now = 2  # �ֵ��°���
            if self.five_step_switch:
                print("��ѡ������N�����������ɷ�ʽ(����Aѡ���Զ����ɣ�����Hѡ���ֶ�����):")  # ����N���ʼ��
                choose_type = input()
                if choose_type.upper().upper() == "A":
                    self.five_step_num = random.randint(2, 5)  # �����������N�������
                    print("������ɵ�����N������Ϊ%d" % self.five_step_num)
                else:
                    print("����������N�������(������һ������):")
                    self.five_step_num = int(input())  # �ֶ���������N�������

            print("��ѡ�񿪾ֵ����ɷ�ʽ(����Aѡ���Զ����ɣ�����Hѡ���ֶ�����):")  # ָ���������ͳ�ʼ��
            specified_start_type = input()
            if specified_start_type.upper() == "A":
                self.gobang_board = specified_start.random_read_db()  # �������26��ָ�������е�һ��
            else:
                self.gobang_board = specified_start.hand_read_db()  # �ֶ�ѡ��26��ָ�������е�һ��

        if specified_start.get_start_type() == "inclined":  # �����Ϣ��ʼ��
            self.specified_start_type = "бָ����"
        else:
            self.specified_start_type = "ֱָ����"
        self.specified_start_name = specified_start.get_start_name()  # ���ָ����������
        self.specified_start_priority = specified_start.get_priority()  # ���ָ���������ȼ�

        self.gobang_board_stack.put(copy.deepcopy(self.gobang_board))  # ���̾�����ջ
        print(self.specified_start_type + ":" + self.specified_start_name + "��")
        self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���

    def opening_type_choose(self):  # ѡ�񿪾ַ�ʽ
        print("��ѡ�񿪾ַ�ʽ(����Rѡ��ָ�����֣�����Fѡ�����ɿ���):")
        opening_type = input()
        if opening_type.upper().upper() == "F":
            print("��ѡ���Ƿ����ý��ֵ��ж�(����Y/N):")
            choice = input()  # ѡ���Ƿ������ֵ��ж�
            if choice.upper() == "Y":
                self.free_start_forbid_choice = 1
            self.free_gobang_start_init()  # �������ɿ��ֳ�ʼ������
        else:
            self.regular_gobang_start_init()  # ����ָ�����ֳ�ʼ������

    def get(self, row, col):  # ���ص�ǰλ�õ�����
        if row < 0 or row >= 15 or col < 0 or col >= 15:
            return 0
        return self.gobang_board[row][col]

    # �ж���Ӯ������0������Ӯ����1������Ӯ����2������Ӯ��
    def check(self):
        board = self.gobang_board
        dirs = ((1, -1), (1, 0), (1, 1), (0, 1))  # �ĸ�������б����ֱ����б��ˮƽ
        for i in range(15):
            for j in range(15):
                if board[i][j] == 0:
                    continue
                id = board[i][j]  # ���������ɫ
                for d in dirs:  # �����ĸ�����
                    x, y = j, i
                    count = 0
                    for k in range(5):
                        if self.get(y, x) != id:  # �������Ƿ񹹳�5��ͬɫ��������һ��
                            break
                        y += d[0]
                        x += d[1]
                        count += 1
                    if count == 5:
                        self.won = {}
                        r, c = i, j
                        for z in range(5):  # ����һ���5��ͬɫ���ӵ�������won����
                            self.won[(r, c)] = 1
                        r += d[0]
                        c += d[1]
                    return id

        return 0

    def player_move(self):  # ����ƶ�����
        if self.Opening_type == 1 and self.gobang_chess_total == 4:
            self.deal_five_step()  # ָ�����֣�������������4������ʱ��ʼ��������N����

        if self.Opening_type == 2 and self.gobang_chess_total == 3 and self.gobang_step_now == 2 and self.free_three_change == 1:
            print("��ѡ���Ƿ����ֽ���(����Y/N)��")
            choose = input()  # ���ɿ��֣���������3�����ӣ���ʱ�ֵ��°��壬���ɿ��ֵ����ֽ���ѡ����Ϊһ
            if choose.upper() == "Y":
                self.Robot_gobang_type = 2  # ���ֽ���������ɺ��ֱ�Ϊ����
                self.robot_move()  # �ֵ�����������°���
            else:
                self.free_three_change = 0  # ���û�н������ֽ������������Ϊ0�����´β���ѯ������Ƿ�ѡ�����ֽ���
                self.player_move()  # �ֵ�����°���

        player_input = input("�����������ƶ���λ��(U:����, Q:�˳�):")  # ����������������
        if len(player_input) == 2:  # ����Ƿ�������������ĸ���ɵ�����
            x = ord(player_input[0].upper()) - ord("A")  # ת������
            y = ord(player_input[1].upper()) - ord("A")
            if self.gobang_step_now == 1:  # ��ʱ�º���
                if 0 < x < 15 and 0 < y < 15:  # �����Ƿ�Ϸ�
                    if self.gobang_board[x][y] == 0:  # �жϵ�ǰ�����Ƿ�Ϊ��
                        self.gobang_board[x][y] = 1  # ���Ϊ����
                    else:  # ��ǰ���겻Ϊ��
                        print("�����ƶ�������")
                        self.player_move()  # ���������������
                        return 0
                else:  # ���겻�Ϸ�
                    print("�����߽�")
                    self.player_move()  # ���������������
                    return 0
                if self.check() == 1:  # �жϺ����Ƿ񹹳�����
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    print("��ϲ�ˣ���Ӯ�ˣ�")
                    self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
                elif self.check() == 2:  # �жϰ����Ƿ񹹳�����
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    print("���ź��������ˣ�")
                    self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
                elif self.check() == 0 and self.gobang_chess_total == 225:  # �ж��Ƿ����
                    print("WOW!��������")
                    self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
                self.gobang_step_now = 2  # �ֵ��°���
            else:  # ��ʱ�°���
                if 0 < x < 15 and 0 < y < 15:  # �����Ƿ�Ϸ�
                    if self.gobang_board[x][y] == 0:  # �жϵ�ǰ�����Ƿ�Ϊ��
                        self.gobang_board[x][y] = 2  # ���Ϊ����
                    else:  # ��ǰ���겻Ϊ��
                        print("�����ƶ�������")
                        self.player_move()  # ���������������
                        return 0
                else:  # ���겻�Ϸ�
                    print("�����߽�")
                    self.player_move()  # ���������������
                    return 0
                if self.check() == 2:  # �жϰ����Ƿ񹹳�����
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    print("��ϲ�ˣ���Ӯ�ˣ�")
                    self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
                elif self.check() == 1:  # �жϺ����Ƿ񹹳�����
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    print("���ź��������ˣ�")
                    self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
                elif self.check() == 0 and self.gobang_chess_total == 225:  # �ж��Ƿ����
                    print("WOW!��������")
                    self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
                self.gobang_step_now = 1  # �ֵ��º���
            player_move_list = [x, y]
            self.stack_push(player_move_list)  # ������ջ
            self.gobang_chess_total += 1  # ����������������1
        elif player_input.upper() == "U":  # ��������д��ĸU���л������
            if self.Opening_type == 2:  # �Ƿ����ɿ���
                if self.round < 3:  # С��3�ֲ��û���
                    print("\nָ�����ֵ�����غϵ���3�أ���������壡")
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    self.player_move()  # �����������
                else:
                    self.gobang_board_undo()  # ����
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    self.player_move()  # ����������ֵ��������
            else:  # ָ������
                if self.round < 5:  # С��5�ֲ��û���
                    print("\nָ�����ֵ�����غϵ���5�أ���������壡")
                    self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                    self.player_move()  # �����������
                else:
                    self.gobang_board_undo()  # ����
        else:  # ���������ĸQ�����˳�����
            self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
        self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
        self.robot_move()  # �ֵ��������������

    def robot_move(self):  # �������ƶ�����
        if self.Opening_type == 1 and self.gobang_chess_total == 4:
            self.deal_five_step()  # ָ�����֣�������������4������ʱ��ʼ��������N����

        print("�������������˼��...")
        noobrobot = NoobRobot.NoobRobot()  # ��������˳�ʼ��

        DEPTH = 3  # ��������ȳ�ʼ��

        noobrobot.board = self.gobang_board  # ��������˵����̾����ʼ��
        noobrobot.Opening_type = self.Opening_type  # ��������˵Ŀ������;����ʼ��
        score, row, col = noobrobot.search(self.gobang_step_now, DEPTH)  # �������������ֺ�����ƶ�λ������
        x = chr(ord("A") + row)
        y = chr(ord("A") + col)

        out_str = ""
        out_str += "����������ƶ���  " + x + y + " (" + str(score) + ")"
        print(out_str)

        if self.gobang_step_now == 1:  # ��ʱ�Ƿ��º���
            self.gobang_board[row][col] = 1  # ���Ϊ����
            if self.check() == 1:  # �жϺ����Ƿ񹹳�����
                self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                print("���ź��������ˣ�")
                self.gobang_board_quit()
            elif self.check() == 2:  # �жϰ����Ƿ񹹳�����
                self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                print("��ϲ�ˣ���Ӯ�ˣ�")
                self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
            elif self.check() == 0 and self.gobang_chess_total == 225:  # �ж��Ƿ����
                print("WOW!��������")
                self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
            self.gobang_step_now = 2  # �ֵ��°���
        else:  # ��ʱ�°���
            self.gobang_board[row][col] = 2  # ���Ϊ����
            if self.Opening_type == 1:  # ָ������
                self.check_forbid_step()  # ���ֵ��ж�
            if self.free_start_forbid_choice == 1:  # ���ɿ��ֽ��ֵ��ʾΪ1����н��ֵ��ж�
                self.check_forbid_step()  # ���ֵ��ж�
            if self.check() == 2:  # �жϰ����Ƿ񹹳�����
                self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                print("���ź��������ˣ�")
                self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
            elif self.check() == 1:  # �жϺ����Ƿ񹹳�����
                self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
                print("��ϲ�ˣ���Ӯ�ˣ�")
                self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
            elif self.check() == 0 and self.gobang_chess_total == 225:  # �ж��Ƿ����
                print("WOW!��������")
                self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
            self.gobang_step_now = 1  # �ֵ��º���

        robot_move_list = [row, col]
        self.stack_push(robot_move_list)  # ������ջ
        self.gobang_chess_total += 1  # ����������������1

        self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
        self.player_move()  # �ֵ��������

    def stack_push(self, move_input):  # �����ˣ�����µ����Լ���ǰ�����ջ
        if self.gobang_step_now != self.Robot_gobang_type:  # ��ʱ�µ��岻�ǲ��������ѡ�����������
            self.Robot_input_stack.put(copy.deepcopy(move_input))  # �������������������ջ
        else:  # ��ʱ�µ��岻�����ѡ�����������
            self.Player_input_stack.put(copy.deepcopy(move_input))  # �������������ջ
        self.gobang_board_stack.put(copy.deepcopy(self.gobang_board))  # ���̾�����ջ

    def deal_five_step(self):  # ����N��
        noobrobot = NoobRobot.NoobRobot()  # ��������˳�ʼ��
        noobrobot.board = self.gobang_board  # ��������˵����̾����ʼ��

        if self.Robot_gobang_type == 1:  # ��ʱ����������Ƿ�Ϊ����
            pos = noobrobot.deal_robot_five_step(self.five_step_num, self.gobang_step_now)  # ��ò��������ѡ�������N���λ������POS����
            num = 1  # ���λ������POS����
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
            out_str += "\n" + "��ѡ���������˵�����" + str(self.five_step_num) + "���ƶ�λ�õı��:"
            print(out_str)
            pos_num = int(input())  # ��Ҵ�POS������ѡ����ʵ�λ������
            row, col = pos[pos_num - 1]
            self.gobang_board[row][col] = 1  # ���Ϊ����
            self.gobang_step_now = 2  # �ֵ��°���

            robot_move_list = [row, col]
            self.stack_push(robot_move_list)  # ������ջ
            self.gobang_chess_total += 1  # ����������������1

            self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
            self.player_move()  # �ֵ��������
        else:  # ��ʱ���Ϊ����
            print("�������������%d��(����һ�����ݣ��ո����)��" % self.five_step_num)
            pos = []
            pos = input().split()  # �����������N���λ������
            moves = []
            if len(pos) != self.five_step_num:  # �ж�λ�����������Ƿ��㹻
                print("���������������%d����ƶ�λ�������������������룡")
                self.deal_five_step()  # ��������
                return 0
            for i in range(self.five_step_num):
                x = ord(pos[i][0].upper()) - ord("A")
                y = ord(pos[i][1].upper()) - ord("A")
                if 0 <= x <= 14 and 0 <= y <= 14:  # �ж������Ƿ�Ϸ�
                    if self.gobang_board[x][y] == 0:  # �ж������Ƿ�Ϊ��
                        moves.append((x, y))  # ������moves����
                    else:  # ���겻Ϊ��
                        print("����������������ƶ�λ�ã��������룡")
                        self.deal_five_step()  # ��������
                        return 0
                else:  # ����λ�ò��Ϸ�
                    print("������������ƶ�λ���д������������룡")
                    self.deal_five_step()  # ��������
                    return 0
            row, col = noobrobot.deal_player_five_step(moves, self.gobang_step_now)  # ����������������N��moves����
            x = chr(ord("A") + row)
            y = chr(ord("A") + col)
            s = ""
            s += x + y
            print("���������ѡ���������%d����ƶ�λ��Ϊ (%s)" % (self.five_step_num, s))
            self.gobang_board[row][col] = 1  # ���Ϊ����
            self.gobang_step_now = 2  # �ֵ��°���

            player_move_list = [row, col]
            self.stack_push(player_move_list)  # ������ջ
            self.gobang_chess_total += 1  # ����������������1

            self.show_the_gobang_board_now(self.gobang_board)  # ��ʾ���̾���
            self.robot_move()  # �ֵ��������������

    def check_forbid_step(self):  # ���ֵ���жϣ������������֣����Ľ��֣���������
        CheckStep = ForbidStep.ForbidStep()
        CheckStep.board = self.gobang_board  # �����жϽ��ֵ�����̾����ʼ��
        for i in range(15):
            for j in range(15):
                if self.gobang_board[i][j] == 1:  # �ж��Ƿ�Ϊ����
                    if CheckStep.charge_three_forbid(i, j):  # �ж��Ƿ�Ϊ�������ֵ�
                        row = chr(ord("A") + i)
                        col = chr(ord("A") + j)
                        s = ""
                        s += row + col
                        print("�ܲ��Ұ���������˵��װ�Ľ��ֵ㣡����е��������ֵ�Ϊ (%s) �������ˣ�" % (s))
                        self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�

                    if CheckStep.charge_four_forbid(i, j):  # �ж��Ƿ�Ϊ���Ľ���
                        row = chr(ord("A") + i)
                        col = chr(ord("A") + j)
                        s = ""
                        s += row + col
                        print("�ܲ��Ұ���������˵��װ�Ľ��ֵ㣡����е����Ľ��ֵ�Ϊ (%s) �������ˣ�" % (s))
                        self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�

                    if CheckStep.charge_long_forbid(i, j):  # �ж��Ƿ�Ϊ��������
                        row = chr(ord("A") + i)
                        col = chr(ord("A") + j)
                        s = ""
                        s += row + col
                        print("�ܲ��Ұ���������˵��װ�Ľ��ֵ㣡����еĳ������ֵ�Ϊ (%s) �������ˣ�" % (s))
                        self.gobang_board_quit()  # ��������Ϣ�������ݿⲢ�˳�
        return 0

    def gobang_go(self):  # ��ֳ�ʼ����ʼ����
        if self.Robot_gobang_type == 1 and self.Opening_type == 1:  # ����������Ƿ�Ϊ���ֲ��ҿ�������Ϊָ������
            print("��ѡ���Ƿ����ֽ���(����Y/N)��")
            choose = input()  # ��������Ƿ����ֽ���
            if choose.upper() == "Y":
                self.Robot_gobang_type = 2  # ��������˱�Ϊ����
                self.robot_move()  # �ֵ��������������
            else:  # ��Ҳ�ѡ�����ֽ���
                self.player_move()  # �ֵ��������
        elif self.Robot_gobang_type == 2 and self.Opening_type == 1:  # ����������Ƿ�Ϊ���ֲ��ҿ�������Ϊָ������
            print("���������˼���Ƿ����ֽ���...")
            if self.specified_start_priority[0] == "1":  # �ж�ָ�������е�������ȼ��Ƿ�Ϊ��������
                print("���������ѡ�񽻻��Ⱥ���")
                self.Robot_gobang_type = 1  # ��������˱�Ϊ����
                self.player_move()  # �ֵ��������
            else:  # ָ�������е�������ȼ�Ϊ��������
                print("��������˾����������Ⱥ���")
                self.robot_move()  # �ֵ��������������
        elif self.Robot_gobang_type == 1 and self.Opening_type == 2:  # ����������Ƿ�Ϊ���ֲ��ҿ�������Ϊ���ɿ���
            self.player_move()  # �ֵ��������
        elif self.Robot_gobang_type == 2 and self.Opening_type == 2:  # ����������Ƿ�Ϊ���ֲ��ҿ�������Ϊ���ɿ���
            self.player_move()  # �ֵ��������


if __name__ == "__main__":
    s = CentralControl()
    s.gobang_type_choose()
    s.opening_type_choose()
    s.gobang_go()
