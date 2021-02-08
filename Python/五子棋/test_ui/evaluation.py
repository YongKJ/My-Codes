# coding=gbk

import copy


# ----------------------------------------------------------------------
# evaluation: 棋盘评估类，给当前棋盘打分用
# ----------------------------------------------------------------------

class evalution(object):

    def __init__(self):
        self.POS = []  # 位置权值，棋盘最中心点权值是7，往外一格-1，最外圈是0
        for i in range(15):
            row = [(7 - max(abs(i - 7), abs(j - 7))) for j in range(15)]
            self.POS.append(tuple(row))
        self.POS = tuple(self.POS)
        self.STWO = 1  # 冲二
        self.STHREE = 2  # 冲三
        self.SFOUR = 3  # 冲四
        self.TWO = 4  # 活二
        self.THREE = 5  # 活三
        self.FOUR = 6  # 活四
        self.FIVE = 7  # 活五
        self.ANALYSED = 255  # 已经分析过
        self.TODO = 0  # 没有分析过
        self.result = [0 for i in range(30)]  # 保存当前直线分析值
        self.line = [0 for i in range(30)]
        self.record = []  # 全盘分析结果 [row][col][方向]
        for i in range(15):
            self.record.append([])
            self.record[i] = []
            for j in range(15):
                self.record[i].append([0, 0, 0, 0])
        self.count = []  # 每种棋局的个数：count[黑棋/白棋][模式]
        for i in range(3):
            data = [0 for i in range(20)]
            self.count.append(data)

    # 分析评估棋盘，返回打分
    def evaluate(self, board, turn):
        score = self._evaluate(board, turn)
        count = self.count
        if score < -9000:
            stone = turn == 1 and 2 or 1
            for i in range(20):
                if count[stone][i] > 0:
                    score -= i
        elif score > 9000:
            stone = turn == 1 and 2 or 1
            for i in range(20):
                if count[stone][i] > 0:
                    score += i
        return score

    # 四个方向（水平，垂直，左斜，右斜）分析评估棋盘，然后根据分析结果打分
    def _evaluate(self, board, turn):
        record, count = self.record, self.count
        TODO, ANALYSED = self.TODO, self.ANALYSED
        # self.reset()

        # 四个方向分析
        for i in range(15):
            boardrow = board[i]
            recordrow = record[i]
            for j in range(15):
                if boardrow[j] != 0:
                    if recordrow[j][0] == TODO:  # 水平有没有分析过？
                        self._analysis_horizon(board, i, j)
                    if recordrow[j][1] == TODO:  # 垂直有没有分析过？
                        self._analysis_vertical(board, i, j)
                    if recordrow[j][2] == TODO:  # 左斜有没有分析过？
                        self._analysis_left(board, i, j)
                    if recordrow[j][3] == TODO:  # 右斜有没有分析过？
                        self._analysis_right(board, i, j)

        FIVE, FOUR, THREE, TWO = self.FIVE, self.FOUR, self.THREE, self.TWO
        SFOUR, STHREE, STWO = self.SFOUR, self.STHREE, self.STWO
        check = {}

        # 分别对白棋黑棋计算：FIVE, FOUR, THREE, TWO等出现的次数
        for c in (FIVE, FOUR, SFOUR, THREE, STHREE, TWO, STWO):
            check[c] = 1
        for i in range(15):
            for j in range(15):
                stone = board[i][j]
                if stone != 0:
                    for k in range(4):
                        ch = record[i][j][k]
                        if ch in check:
                            count[stone][ch] += 1

        # 如果有五连则马上返回分数
        BLACK, WHITE = 1, 2
        if turn == WHITE:  # 当前棋是白棋
            if count[BLACK][FIVE] > 0:
                return -9999
            if count[WHITE][FIVE] > 0:
                return 9999
        else:  # 当前棋是黑棋
            if count[WHITE][FIVE] > 0:
                return -9999
            if count[BLACK][FIVE] > 0:
                return 9999

        # 如果存在两个冲四，则相当于有一个活四
        if count[WHITE][SFOUR] >= 2:
            count[WHITE][FOUR] += 1
        if count[BLACK][SFOUR] >= 2:
            count[BLACK][FOUR] += 1

        # 具体打分
        wvalue, bvalue = 0, 0
        if turn == WHITE:
            if count[WHITE][FOUR] > 0:
                return 9990
            if count[WHITE][SFOUR] > 0:
                return 9980
            if count[BLACK][FOUR] > 0:
                return -9970
            if count[BLACK][SFOUR] and count[BLACK][THREE]:
                return -9960
            if count[WHITE][THREE] and count[BLACK][SFOUR] == 0:
                return 9950
            if count[BLACK][THREE] > 1 and \
                    count[WHITE][SFOUR] == 0 and \
                    count[WHITE][THREE] == 0 and \
                    count[WHITE][STHREE] == 0:
                return -9940

            if count[WHITE][THREE] > 1:
                wvalue += 2000
            elif count[WHITE][THREE]:
                wvalue += 200
            if count[BLACK][THREE] > 1:
                bvalue += 500
            elif count[BLACK][THREE]:
                bvalue += 100

            if count[WHITE][STHREE]:
                wvalue += count[WHITE][STHREE] * 10
            if count[BLACK][STHREE]:
                bvalue += count[BLACK][STHREE] * 10
            if count[WHITE][TWO]:
                wvalue += count[WHITE][TWO] * 4
            if count[BLACK][TWO]:
                bvalue += count[BLACK][TWO] * 4
            if count[WHITE][STWO]:
                wvalue += count[WHITE][STWO]
            if count[BLACK][STWO]:
                bvalue += count[BLACK][STWO]

        else:

            if count[BLACK][FOUR] > 0:
                return 9990
            if count[BLACK][SFOUR] > 0:
                return 9980
            if count[WHITE][FOUR] > 0:
                return -9970
            if count[WHITE][SFOUR] and count[WHITE][THREE]:
                return -9960
            if count[BLACK][THREE] and count[WHITE][SFOUR] == 0:
                return 9950
            if count[WHITE][THREE] > 1 and \
                    count[BLACK][SFOUR] == 0 and \
                    count[BLACK][THREE] == 0 and \
                    count[BLACK][STHREE] == 0:
                return -9940

            if count[BLACK][THREE] > 1:
                bvalue += 2000
            elif count[BLACK][THREE]:
                bvalue += 200
            if count[WHITE][THREE] > 1:
                wvalue += 500
            elif count[WHITE][THREE]:
                wvalue += 100

            if count[BLACK][STHREE]:
                bvalue += count[BLACK][STHREE] * 10
            if count[WHITE][STHREE]:
                wvalue += count[WHITE][STHREE] * 10
            if count[BLACK][TWO]:
                bvalue += count[BLACK][TWO] * 4
            if count[WHITE][TWO]:
                wvalue += count[WHITE][TWO] * 4
            if count[BLACK][STWO]:
                bvalue += count[BLACK][STWO]
            if count[WHITE][STWO]:
                wvalue += count[WHITE][STWO]

        # 加上位置权值，棋盘最中心点权值是7，往外一格-1，最外圈是0
        wc, bc = 0, 0
        for i in range(15):
            for j in range(15):
                stone = board[i][j]
                if stone != 0:
                    if stone == WHITE:
                        wc += self.POS[i][j]
                    else:
                        bc += self.POS[i][j]
        wvalue += wc
        bvalue += bc

        if turn == WHITE:
            return wvalue - bvalue

        return bvalue - wvalue

    # 分析横向
    def _analysis_horizon(self, board, i, j):
        line, result, record = self.line, self.result, self.record
        TODO = self.TODO
        for y in range(15):
            line[y] = board[i][y]
        self.analysis_line(line, result, 15, j)
        for y in range(15):
            if result[y] != TODO:
                record[i][y][0] = result[y]
        return record[i][j][0]

    # 分析纵向
    def _analysis_vertical(self, board, i, j):
        line, result, record = self.line, self.result, self.record
        TODO = self.TODO
        for x in range(15):
            line[x] = board[x][j]
        self.analysis_line(line, result, 15, i)
        for x in range(15):
            if result[x] != TODO:
                record[x][j][1] = result[x]
        return record[i][j][1]

    # 分析左斜
    def _analysis_left(self, board, i, j):
        line, result, record = self.line, self.result, self.record
        TODO = self.TODO
        if i < j:
            x, y = j - i, 0
        else:
            x, y = 0, i - j
        k = 0
        while k < 15:
            if x + k > 14 or y + k > 14:
                break
            line[k] = board[y + k][x + k]
            k += 1
        self.analysis_line(line, result, k, j - x)
        for s in range(k):
            if result[s] != TODO:
                record[y + s][x + s][2] = result[s]
        return record[i][j][2]

    # 分析右斜
    def _analysis_right(self, board, i, j):
        line, result, record = self.line, self.result, self.record
        TODO = self.TODO
        if 14 < i + j:
            x, y, realnum = j - 14 + i, 14, 14 - i
        else:
            x, y, realnum = 0, i + j, j
        k = 0
        while k < 15:
            if x + k > 14 or y - k < 0:
                break
            line[k] = board[y - k][x + k]
            k += 1
        self.analysis_line(line, result, k, j - x)
        for s in range(k):
            if result[s] != TODO:
                record[y - s][x + s][3] = result[s]
        return record[i][j][3]

    # 分析一条线：五四三二等棋型
    def analysis_line(self, line, record, num, pos):
        TODO, ANALYSED = self.TODO, self.ANALYSED
        THREE, STHREE = self.THREE, self.STHREE
        FOUR, SFOUR = self.FOUR, self.SFOUR
        while len(line) < 30:
            line.append(0xf)
        while len(record) < 30:
            record.append(TODO)
        for i in range(num, 30):
            line[i] = 0xf
        for i in range(num):
            record[i] = TODO
        if num < 5:
            for i in range(num):
                record[i] = ANALYSED
            return 0

        stone = line[pos]
        inverse = (0, 1, 2)[stone]
        num -= 1

        # 相同棋子的左右边界
        xl = pos
        xr = pos
        while xl > 0:  # 探索左边界
            if line[xl - 1] != stone:
                break
            xl -= 1
        while xr < num:  # 探索右边界
            if line[xr + 1] != stone:
                break
            xr += 1

        # 相同棋子左右两边的范围（查找不相同的棋子，空格和相反色棋子）
        left_range = xl
        right_range = xr
        while left_range > 0:  # 探索左边范围（非对方棋子的格子坐标）
            if line[left_range - 1] == inverse:
                break
            left_range -= 1
        while right_range < num:  # 探索左边范围（非对方棋子的格子坐标）
            if line[right_range + 1] == inverse:
                break
            right_range += 1

        # 如果改直线范围小于5，则直接返回
        if right_range - left_range < 4:
            for k in range(left_range, right_range + 1):
                record[k] = ANALYSED
            return 0

        # 设置已经分析过
        for k in range(xl, xr + 1):
            record[k] = ANALYSED

        srange = xr - xl

        # 如果是5连
        if srange >= 4:
            record[pos] = self.FIVE  # 五连（XXXXX）
            return self.FIVE

        # 如果是4连
        if srange == 3:
            left4 = False
            if xl > 0:
                if line[xl - 1] == 0:  # 左边是否是空格
                    left4 = True
            if xr < num:
                if line[xr + 1] == 0:  # 右边是空格
                    if left4:
                        record[pos] = self.FOUR  # 活四（.XXXX.）
                    else:
                        record[pos] = self.SFOUR  # 冲四（OXXXX.）
                else:
                    if left4:
                        record[pos] = self.SFOUR  # 冲四（.XXXXO）
            else:
                if left4:
                    record[pos] = self.SFOUR  # 冲四（.XXXX|）
            return record[pos]

        # 如果是3连
        if srange == 2:
            left3 = False  # 左边是否有空格
            if xl > 0:
                if line[xl - 1] == 0:  # 左边有气
                    if xl > 1 and line[xl - 2] == stone:
                        record[xl] = SFOUR  # 冲四（X.XXX）
                        record[xl - 2] = ANALYSED
                    else:
                        left3 = True  # 左边有空格
                elif xr == num or line[xr + 1] != 0:  # 死三(OXXX|)或(OXXXO)
                    return 0
            if xr < num:
                if line[xr + 1] == 0:  # 右边有气
                    if xr < num - 1 and line[xr + 2] == stone:
                        record[xr] = SFOUR  # 冲四（XXX.X）
                        record[xr + 2] = ANALYSED
                    elif left3:
                        record[xr] = THREE  # 活三（.XXX.）
                    else:
                        record[xr] = STHREE  # 冲三（OXXX.）
                elif record[xl] == SFOUR:  # 已经是冲四
                    return record[xl]
                elif left3:
                    record[pos] = STHREE  # 冲三（.XXXO）
            else:
                if record[xl] == SFOUR:  # 已经是冲四
                    return record[xl]
                if left3:
                    record[pos] = STHREE  # 冲三（.XXX|）
            return record[pos]

        # 如果是2连
        if srange == 1:
            left2 = False
            if xl > 2:
                if line[xl - 1] == 0:  # 左边有气
                    if line[xl - 2] == stone:
                        if line[xl - 3] == stone:
                            record[xl] = SFOUR  # 冲四（XX.XX）
                            record[xl - 2] = ANALYSED
                            record[xl - 3] = ANALYSED
                        elif line[xl - 3] == 0:
                            record[xl] = STHREE  # 冲三（.X.XX）
                            record[xl - 2] = ANALYSED
                    else:
                        left2 = True  # 左边有空格
            if xr < num:
                if line[xr + 1] == 0:  # 右边有气
                    if xr < num - 2 and line[xr + 2] == stone:
                        if line[xr + 3] == stone:
                            record[xr] = SFOUR  # 冲四（XX.XX）
                            record[xr + 2] = ANALYSED
                            record[xr + 3] = ANALYSED
                        elif line[xr + 3] == 0:
                            record[xr] = left2 and THREE or STHREE  # 活三（.XX.X.）或冲三（OXX.X.）
                            record[xr + 2] = ANALYSED
                    else:
                        if record[xl] == SFOUR:  # 左边已经是冲四
                            return record[xl]
                        if record[xl] == STHREE:  # 左边已经是冲三
                            record[xl] = THREE  # 左边由冲三变为活三（.X.XX）变（.X.XX.）
                            return record[xl]
                        if left2:
                            record[pos] = self.TWO  # 活二（.XX.）
                        else:
                            record[pos] = self.STWO  # 冲二（OXX.）
                else:
                    if record[xl] == SFOUR:  # 左边已经是冲四
                        return record[xl]
                    if left2:
                        record[pos] = self.STWO  # 冲二（.XXO）
            return record[pos]
        return 0

