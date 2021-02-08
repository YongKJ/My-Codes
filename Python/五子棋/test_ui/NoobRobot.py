# coding=gbk

import evaluation
import threading
import ForbidStep


class NoobRobot(object):

    def __init__(self):
        self.POS = []  # 位置权值，棋盘最中心点权值是7，往外一格-1，最外圈是0
        for i in range(15):
            row = [(7 - max(abs(i - 7), abs(j - 7))) for j in range(15)]
            self.POS.append(tuple(row))
        self.POS = tuple(self.POS)
        self.board = [[0 for n in range(15)] for i in range(15)]  # 当前棋盘矩阵
        self.maxdepth = 3  # 递归最大层数
        self.Opening_type = 0  # 自由开局或指定开局

    # 产生当前棋局的走法
    def genmove(self, turn):
        board = self.board

        # 极致砍博弈树（极致剪枝）
        gobang_pos_horizon = []  # 横向：获得水平方向有棋子的行数
        for i in range(15):
            for j in range(15):
                if board[i][j] != 0:
                    gobang_pos_horizon.append(i)
                    break
        row1 = gobang_pos_horizon[0]
        row2 = gobang_pos_horizon[len(gobang_pos_horizon) - 1]
        # 最小行数减1，最大行数加1，目的是确定构成恰好包含五子棋的小矩阵的行边界
        if row1 > 0:
            row1 -= 1
        if row2 < 14:
            row2 += 1

        gobang_pos_vertical = []  # 纵向：获得垂直方向有棋子的行数
        for i in range(15):
            for j in range(15):
                if board[j][i] != 0:
                    gobang_pos_vertical.append(i)
                    break
        col1 = gobang_pos_vertical[0]
        col2 = gobang_pos_vertical[len(gobang_pos_vertical) - 1]
        # 最小列数减1，最大列数加1，目的是确定构成恰好包含五子棋的小矩阵的列边界
        if col1 > 0:
            col1 -= 1
        if col2 < 14:
            col2 += 1

        dir = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [-1, -1], [1, -1], [-1, 1]]  # 相对于当前坐标的八个方向的移动坐标
        moves = []
        POSES = self.POS  # 位置权值，棋盘最中心点权值是7，往外一格-1，最外圈是0
        for i in range(row1, row2 + 1):  # 遍历棋盘矩阵
            for j in range(col1, col2 + 1):
                for k in range(8):  # 每个坐标向八个方向移动一次
                    x = dir[k][0]
                    y = dir[k][1]
                    if 0 <= i + x <= 14 and 0 <= j + y <= 14:  # 判断移动后的坐标是否合法
                        if board[i][j] == 0 and board[i + x][j + y] != 0:  # 判断当前坐标是否为空，并且移动后的坐标是否有棋子（寻找跟棋子相邻的空位置）
                            if turn == 1:  # 当前是否是下黑棋子
                                if self.Opening_type == 1:  # 开局是否为指定开局
                                    forbid_step = ForbidStep.ForbidStep()
                                    if not forbid_step.deal_noobrobot_move(i, j):  # 判断当前空位置是否为禁手点，若否则位置权值和坐标入moves对列
                                        score = POSES[i][j]
                                        moves.append((score, i, j))
                                        break
                                else:  # 若为自由开局，则位置权值和坐标直接入moves对列
                                    score = POSES[i][j]
                                    moves.append((score, i, j))
                                    break
                            else:  # 若当前为下白棋子，则位置权值和坐标直接入moves对列
                                score = POSES[i][j]
                                moves.append((score, i, j))
                                break
        moves.sort()  # moves队列排序
        moves.reverse()  # moves队列从大到小排序
        return moves  # 返回moves队列

    # 递归搜索：返回最佳分数以及产生最佳走法
    def _search(self, turn, depth, alpha=-0x7fffffff, beta=0x7fffffff):

        # 深度为零则评估棋盘并返回
        if depth <= 0:
            t = DealScoreWithThread(self.board, turn)
            t.start()
            score = t.score
            return score

        # 开启评分线程，并获得线程中当前棋盘的评分
        t = DealScoreWithThread(self.board, turn)
        t.start()
        score = t.score
        # 如果游戏结束则立马返回
        if abs(score) >= 9999 and depth < self.maxdepth:
            return score

        # 产生新走法
        moves = self.genmove(turn)
        # 最好的移动位置初始化
        bestmove = None

        # 枚举当前所有走法
        for score, row, col in moves:
            # 标记当前走法到棋盘
            self.board[row][col] = turn

            # 计算下一回合该谁走
            nturn = turn == 1 and 2 or 1

            # 深度优先搜索，返回评分， 走的行和走的列
            score = - self._search(nturn, depth - 1, -beta, -alpha)

            # 清除棋盘上当前走法
            self.board[row][col] = 0

            # 计算最好分值的走法
            # alpha/ beta 剪枝
            if score > alpha:
                alpha = score
                bestmove = (row, col)
                if alpha >= beta:
                    break

        # 如果是第一层则记录最好的走法
        if depth == self.maxdepth and bestmove:
            self.bestmove = bestmove

        # 返回当前最好的分数和该分数的对应走法
        return alpha

    # 搜索初始化，传入当前是该谁走(turn=1/2)，以及搜索深度(depth)
    def search(self, turn, depth=3):
        self.maxdepth = depth  # 获得最大递归深度
        self.bestmove = None  # 最好位置初始化
        score = self._search(turn, depth)  # 获得最好的棋盘评分
        if abs(score) > 8000:  # 分手大于8000，则以深度1再搜索最好的棋盘评分
            self.maxdepth = depth
            score = self._search(turn, 1)
        row, col = self.bestmove
        return score, row, col  # 返回最好棋盘评分和最佳移动位置坐标

    def deal_robot_five_step(self, five_num, turn):  # 处理菜鸟机器人的五手N打，此时菜鸟机器人选择的是先手
        score, x, y = self.search(turn, 3)  # 首先获得最好棋盘评分和最佳移动位置坐标
        moves = self.genmove(turn)  # 获得当前所有可移动的位置
        POS = []
        POS.append((x, y))  # 最佳移动位置坐标入POS队列
        num = 1
        for score, row, col in moves:  # 遍历当前所有可移动的位置
            if num == five_num:  # 判断入POS队列的坐标数是否已经足够
                break
            if row == x and col == y:  # 如果最近位置坐标在当前所有可移动的位置moves队列，则跳过
                continue
            POS.append((row, col))  # 从当前所有可移动的位置moves队列选择较优的位置坐标入POS队列
            num += 1
        return POS  # 返回菜鸟机器人选择的五手N打的位置坐标POS队列

    def deal_player_five_step(self, pos, turn):  # 处理玩家的五手N打，此时玩家选择的是先手
        moves = []
        for row, col in pos:  # 遍历玩家输入的五手N打坐标
            self.board[row][col] = turn  # 在当前位置下棋
            t = DealScoreWithThread(self.board, turn)  # 计算当前棋局的评分
            t.start()
            score = t.score

            moves.append((score, row, col))  # 评分，坐标入moves队列
            self.board[row][col] = 0
        moves.sort()  # 从小到大排序
        score, row, col = moves[0]
        return row, col  # 返回第一个排序后的moves队列中的第一个坐标


class DealScoreWithThread(threading.Thread):  # 开一个线程计算当前棋局的评分

    def __init__(self, board, turn):
        super(DealScoreWithThread, self).__init__()
        self.evaluator = evaluation.evalution()
        self.board = board
        self.turn = turn
        self.score = 0

    def run(self):
        self.score = self.evaluator.evaluate(self.board, self.turn)
