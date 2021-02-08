# coding=gbk

import evaluation
import threading
import ForbidStep


class NoobRobot(object):

    def __init__(self):
        self.POS = []  # λ��Ȩֵ�����������ĵ�Ȩֵ��7������һ��-1������Ȧ��0
        for i in range(15):
            row = [(7 - max(abs(i - 7), abs(j - 7))) for j in range(15)]
            self.POS.append(tuple(row))
        self.POS = tuple(self.POS)
        self.board = [[0 for n in range(15)] for i in range(15)]  # ��ǰ���̾���
        self.maxdepth = 3  # �ݹ�������
        self.Opening_type = 0  # ���ɿ��ֻ�ָ������

    # ������ǰ��ֵ��߷�
    def genmove(self, turn):
        board = self.board

        # ���¿������������¼�֦��
        gobang_pos_horizon = []  # ���򣺻��ˮƽ���������ӵ�����
        for i in range(15):
            for j in range(15):
                if board[i][j] != 0:
                    gobang_pos_horizon.append(i)
                    break
        row1 = gobang_pos_horizon[0]
        row2 = gobang_pos_horizon[len(gobang_pos_horizon) - 1]
        # ��С������1�����������1��Ŀ����ȷ������ǡ�ð����������С������б߽�
        if row1 > 0:
            row1 -= 1
        if row2 < 14:
            row2 += 1

        gobang_pos_vertical = []  # ���򣺻�ô�ֱ���������ӵ�����
        for i in range(15):
            for j in range(15):
                if board[j][i] != 0:
                    gobang_pos_vertical.append(i)
                    break
        col1 = gobang_pos_vertical[0]
        col2 = gobang_pos_vertical[len(gobang_pos_vertical) - 1]
        # ��С������1�����������1��Ŀ����ȷ������ǡ�ð����������С������б߽�
        if col1 > 0:
            col1 -= 1
        if col2 < 14:
            col2 += 1

        dir = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [-1, -1], [1, -1], [-1, 1]]  # ����ڵ�ǰ����İ˸�������ƶ�����
        moves = []
        POSES = self.POS  # λ��Ȩֵ�����������ĵ�Ȩֵ��7������һ��-1������Ȧ��0
        for i in range(row1, row2 + 1):  # �������̾���
            for j in range(col1, col2 + 1):
                for k in range(8):  # ÿ��������˸������ƶ�һ��
                    x = dir[k][0]
                    y = dir[k][1]
                    if 0 <= i + x <= 14 and 0 <= j + y <= 14:  # �ж��ƶ���������Ƿ�Ϸ�
                        if board[i][j] == 0 and board[i + x][j + y] != 0:  # �жϵ�ǰ�����Ƿ�Ϊ�գ������ƶ���������Ƿ������ӣ�Ѱ�Ҹ��������ڵĿ�λ�ã�
                            if turn == 1:  # ��ǰ�Ƿ����º�����
                                if self.Opening_type == 1:  # �����Ƿ�Ϊָ������
                                    forbid_step = ForbidStep.ForbidStep()
                                    if not forbid_step.deal_noobrobot_move(i, j):  # �жϵ�ǰ��λ���Ƿ�Ϊ���ֵ㣬������λ��Ȩֵ��������moves����
                                        score = POSES[i][j]
                                        moves.append((score, i, j))
                                        break
                                else:  # ��Ϊ���ɿ��֣���λ��Ȩֵ������ֱ����moves����
                                    score = POSES[i][j]
                                    moves.append((score, i, j))
                                    break
                            else:  # ����ǰΪ�°����ӣ���λ��Ȩֵ������ֱ����moves����
                                score = POSES[i][j]
                                moves.append((score, i, j))
                                break
        moves.sort()  # moves��������
        moves.reverse()  # moves���дӴ�С����
        return moves  # ����moves����

    # �ݹ�������������ѷ����Լ���������߷�
    def _search(self, turn, depth, alpha=-0x7fffffff, beta=0x7fffffff):

        # ���Ϊ�����������̲�����
        if depth <= 0:
            t = DealScoreWithThread(self.board, turn)
            t.start()
            score = t.score
            return score

        # ���������̣߳�������߳��е�ǰ���̵�����
        t = DealScoreWithThread(self.board, turn)
        t.start()
        score = t.score
        # �����Ϸ������������
        if abs(score) >= 9999 and depth < self.maxdepth:
            return score

        # �������߷�
        moves = self.genmove(turn)
        # ��õ��ƶ�λ�ó�ʼ��
        bestmove = None

        # ö�ٵ�ǰ�����߷�
        for score, row, col in moves:
            # ��ǵ�ǰ�߷�������
            self.board[row][col] = turn

            # ������һ�غϸ�˭��
            nturn = turn == 1 and 2 or 1

            # ��������������������֣� �ߵ��к��ߵ���
            score = - self._search(nturn, depth - 1, -beta, -alpha)

            # ��������ϵ�ǰ�߷�
            self.board[row][col] = 0

            # ������÷�ֵ���߷�
            # alpha/ beta ��֦
            if score > alpha:
                alpha = score
                bestmove = (row, col)
                if alpha >= beta:
                    break

        # ����ǵ�һ�����¼��õ��߷�
        if depth == self.maxdepth and bestmove:
            self.bestmove = bestmove

        # ���ص�ǰ��õķ����͸÷����Ķ�Ӧ�߷�
        return alpha

    # ������ʼ�������뵱ǰ�Ǹ�˭��(turn=1/2)���Լ��������(depth)
    def search(self, turn, depth=3):
        self.maxdepth = depth  # ������ݹ����
        self.bestmove = None  # ���λ�ó�ʼ��
        score = self._search(turn, depth)  # �����õ���������
        if abs(score) > 8000:  # ���ִ���8000���������1��������õ���������
            self.maxdepth = depth
            score = self._search(turn, 1)
        row, col = self.bestmove
        return score, row, col  # ��������������ֺ�����ƶ�λ������

    def deal_robot_five_step(self, five_num, turn):  # �����������˵�����N�򣬴�ʱ���������ѡ���������
        score, x, y = self.search(turn, 3)  # ���Ȼ������������ֺ�����ƶ�λ������
        moves = self.genmove(turn)  # ��õ�ǰ���п��ƶ���λ��
        POS = []
        POS.append((x, y))  # ����ƶ�λ��������POS����
        num = 1
        for score, row, col in moves:  # ������ǰ���п��ƶ���λ��
            if num == five_num:  # �ж���POS���е��������Ƿ��Ѿ��㹻
                break
            if row == x and col == y:  # ������λ�������ڵ�ǰ���п��ƶ���λ��moves���У�������
                continue
            POS.append((row, col))  # �ӵ�ǰ���п��ƶ���λ��moves����ѡ����ŵ�λ��������POS����
            num += 1
        return POS  # ���ز��������ѡ�������N���λ������POS����

    def deal_player_five_step(self, pos, turn):  # ������ҵ�����N�򣬴�ʱ���ѡ���������
        moves = []
        for row, col in pos:  # ����������������N������
            self.board[row][col] = turn  # �ڵ�ǰλ������
            t = DealScoreWithThread(self.board, turn)  # ���㵱ǰ��ֵ�����
            t.start()
            score = t.score

            moves.append((score, row, col))  # ���֣�������moves����
            self.board[row][col] = 0
        moves.sort()  # ��С��������
        score, row, col = moves[0]
        return row, col  # ���ص�һ��������moves�����еĵ�һ������


class DealScoreWithThread(threading.Thread):  # ��һ���̼߳��㵱ǰ��ֵ�����

    def __init__(self, board, turn):
        super(DealScoreWithThread, self).__init__()
        self.evaluator = evaluation.evalution()
        self.board = board
        self.turn = turn
        self.score = 0

    def run(self):
        self.score = self.evaluator.evaluate(self.board, self.turn)
