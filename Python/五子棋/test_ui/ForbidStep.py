# coding=gbk

import copy


class ForbidStep(object):

    def __init__(self):
        self.board = [[0 for n in range(15)] for i in range(15)]

        # 三三禁手
        # 有普通活三的三三禁手
        self.ThreeThree = []
        self.ThreeThree_blank = []

        self.ThreeThree1 = [[0, 0, 1], [1, 1, 0], [-1, -1, 1], [-2, -2, 1], [-3, -3, 0],  # 符合三三禁手要求的坐标
                            [-1, 1, 0], [1, -1, 1], [2, -2, 1], [3, -3, 0]]
        self.ThreeThree1_blank = [[2, 2, 0], [-4, -4, 0], [-2, 2, 0], [4, -4, 0]]  # 活三两端的空格坐标
        self.ThreeThree.append(self.ThreeThree1)
        self.ThreeThree_blank.append(self.ThreeThree1_blank)

        self.ThreeThree2 = [[0, 0, 1], [1, 0, 1], [2, 0, 0], [-1, 0, 1], [-2, 0, 0],
                            [1, 1, 1], [2, 2, 0], [-1, -1, 0], [-2, -2, 1], [-3, -3, 0]]
        self.ThreeThree2_blank = [[3, 0, 0], [-3, 0, 0]]
        self.ThreeThree.append(self.ThreeThree2)
        self.ThreeThree_blank.append(self.ThreeThree2_blank)

        self.ThreeThree3 = [[0, 0, 1], [1, 1, 1], [2, 2, 0], [-1, -1, 1], [-2, -2, 0],
                            [0, 1, 0], [0, -1, 1], [0, -2, 1], [0, -3, 0]]
        self.ThreeThree3_blank = [[3, 3, 0], [-3, -3, 0], [0, 2, 0], [0, -4, 0]]
        self.ThreeThree.append(self.ThreeThree3)
        self.ThreeThree_blank.append(self.ThreeThree3_blank)

        self.ThreeThree4 = [[0, 0, 1], [1, 0, 1], [2, 0, 0], [-1, 0, 0], [-2, 0, 1], [-3, 0, 0],
                            [0, 1, 0], [0, -1, 1], [0, -2, 1], [0, -3, 0]]
        self.ThreeThree4_blank = [[3, 0, 0], [-4, 0, 0], [0, 2, 0], [0, -4, 0]]
        self.ThreeThree.append(self.ThreeThree4)
        self.ThreeThree_blank.append(self.ThreeThree4_blank)

        self.ThreeThree5 = [[0, 0, 1], [1, 1, 1], [2, 2, 0], [-1, -1, 1], [-2, -2, 0],
                            [1, -1, 0], [-1, 1, 1], [-2, 2, 1], [-3, 3, 0]]
        self.ThreeThree5_blank = [[3, 3, 0], [-3, -3, 0], [2, -2, 0], [-4, 4, 0]]
        self.ThreeThree.append(self.ThreeThree5)
        self.ThreeThree_blank.append(self.ThreeThree5_blank)

        self.ThreeThree6 = [[0, 0, 1], [1, 0, 0], [-1, 0, 1], [-2, 0, 1], [-3, 0, 0],
                            [1, 1, 0], [2, 2, 1], [3, 3, 1], [4, 4, 0], [-1, 1, 0]]
        self.ThreeThree6_blank = [[2, 0, 0], [-4, 0, 0]]
        self.ThreeThree.append(self.ThreeThree6)
        self.ThreeThree_blank.append(self.ThreeThree6_blank)

        self.ThreeThree7 = [[0, 0, 1], [1, 0, 1], [2, 0, 0], [-1, 0, 1], [-2, 0, 0],
                            [-1, 1, 1], [-2, 2, 0], [1, -1, 1], [2, -2, 0]]
        self.ThreeThree7_blank = [[3, 0, 0], [-3, 0, 0], [3, -3, 0], [-3, 3, 0]]
        self.ThreeThree.append(self.ThreeThree7)
        self.ThreeThree_blank.append(self.ThreeThree7_blank)

        # 特殊的三三禁手
        self.ThreeThree8 = [[0, 0, 1], [0, 1, 1], [0, 2, 0], [0, 3, 1], [0, 4, 0], [0, -1, 0],
                            [1, 0, 0], [-1, 0, 1], [-2, 0, 0], [-3, 0, 1], [-4, 0, 0]]
        self.ThreeThree.append(self.ThreeThree8)

        # 四四禁手
        self.FourFour = []
        self.FourFour1 = [[0, 0, 1], [1, 1, 0], [-1, -1, 1], [-2, -2, 1], [-3, -3, 1], [-4, -4, 0],
                          [-1, 1, 0], [1, -1, 1], [2, -2, 1], [3, -3, 1], [4, -4, 0]]
        self.FourFour.append(self.FourFour1)

        self.FourFour2 = [[0, 0, 1], [1, 1, 1], [2, 2, 0], [-1, -1, 1], [-2, -2, 1], [-3, -3, 0],
                          [-1, 0, 1], [1, 0, 1], [2, 0, 0], [3, 0, 1]]
        self.FourFour.append(self.FourFour2)

        self.FourFour3 = [[0, 0, 1], [1, 0, 1], [2, 0, 0], [3, 0, 1], [-1, 0, 1], [-2, 0, 0], [-3, 0, 1]]
        self.FourFour.append(self.FourFour3)

        self.FourFour4 = [[0, 0, 1], [1, 0, 1], [2, 0, 1], [3, 0, 2], [-1, 0, 1], [-2, 0, 0],
                          [0, -1, 0], [0, -2, 1], [0, -3, 1], [0, -4, 1], [0, -5, 2]]
        self.FourFour.append(self.FourFour4)

        self.FourFour5 = [[0, 0, 1], [1, 0, 0], [2, 0, 1], [3, 0, 1], [-1, 0, 1],
                          [1, -1, 0], [2, -2, 1], [3, -3, 1], [4, -4, 1]]
        self.FourFour.append(self.FourFour5)

        self.FourFour6 = [[0, 0, 1], [0, 1, 0], [0, -1, 1], [0, -2, 1], [0, -3, 1], [0, -4, 2],
                          [1, 0, 0], [-1, 0, 1], [-2, 0, 1], [-3, 0, 1], [-4, 0, 2]]
        self.FourFour.append(self.FourFour6)

        self.FourFour7 = [[0, 0, 1], [1, 0, 1], [2, 0, 1], [3, 0, 0], [4, 0, 1],
                          [-1, 0, 0], [-2, 0, 1]]
        self.FourFour.append(self.FourFour7)

        self.FourFour8 = [[0, 0, 1], [1, 0, 0], [2, 0, 1], [3, 0, 1],
                          [-1, 0, 1], [-2, 0, 0], [-3, 0, 1], [-4, 0, 1]]
        self.FourFour.append(self.FourFour8)

        self.FourFour9 = [[0, 0, 1], [1, 0, 0], [2, 0, 1], [3, 0, 1], [4, 0, 1], [5, 0, 2],
                          [-1, 0, 0], [-2, 0, 1], [-3, 0, 1], [-4, 0, 1], [-5, 0, 2]]
        self.FourFour.append(self.FourFour9)

        # 长连禁手
        self.LongLong = []
        self.LongLong1 = [[0, 0, 1], [0, 1, 1], [0, -1, 1], [0, -2, 1], [0, -3, 1], [0, -4, 1]]
        self.LongLong.append(self.LongLong1)

        self.LongLong2 = [[0, 0, 1], [1, 0, 1], [2, 0, 1], [3, 0, 1], [-1, 0, 1], [-2, 0, 1]]
        self.LongLong.append(self.LongLong2)

    def get_spin_pos(self, x, y):  # 返回逆时针旋转45度后的坐标
        if x == 0 or y == 0:
            row = x - y
            col = x + y
        else:
            row = (x - y) // 2
            col = (x + y) // 2
        return row, col

    def judge_the_pos(self, row, col, pos):  # 判断当前位置是否符合禁手点的要求
        x = row + pos[0]
        y = col + pos[1]
        if 0 <= x <= 14 and 0 <= y <= 14:
            if self.board[x][y] == pos[2]:
                return True
        return False

    def judge_the_pos_blank(self, row, col, pos1, pos2):  # 判断活三两端最外边的空格是否符合构成活三的要求
        x1 = row + pos1[0]
        y1 = col + pos1[1]
        x2 = row + pos1[0]
        y2 = col + pos1[1]
        if 0 <= x1 <= 14 and 0 <= y1 <= 14 and 0 <= x2 <= 14 and 0 <= y2 <= 14:
            if self.board[x1][y1] == pos1[2] or self.board[x2][y2] == pos2[2]:
                return True
        elif 0 <= x1 <= 14 and 0 <= y1 <= 14 and not (0 <= x2 <= 14 and 0 <= y2 <= 14):
            if self.board[x1][y1] == pos1[2]:
                return True
        elif not (0 <= x1 <= 14 and 0 <= y1 <= 14) and 0 <= x2 <= 14 and 0 <= y2 <= 14:
            if self.board[x2][y2] == pos2[2]:
                return True
        return False

    def charge_three_forbid(self, row, col):  # 判断三三禁手
        ThreeThree = copy.deepcopy(self.ThreeThree)
        ThreeThree_bank = copy.deepcopy(self.ThreeThree_blank)

        for i in range(len(ThreeThree)):
            for k in range(8):  # 旋转8次，每次逆时针选择45度

                for j in range(len(ThreeThree[i])):  # 符合三三禁手的坐标旋转
                    x = ThreeThree[i][j][0]
                    y = ThreeThree[i][j][1]
                    x1, y1 = self.get_spin_pos(x, y)
                    ThreeThree[i][j][0] = x1
                    ThreeThree[i][j][1] = y1

                if i < len(ThreeThree_bank):
                    for j in range(len(ThreeThree_bank[i])):  # 三手禁手中活三两端的空格旋转
                        x = ThreeThree_bank[i][j][0]
                        y = ThreeThree_bank[i][j][1]
                        x1, y1 = self.get_spin_pos(x, y)
                        ThreeThree_bank[i][j][0] = x1
                        ThreeThree_bank[i][j][1] = y1

                flag = True

                for j in range(len(ThreeThree[i])):
                    if self.judge_the_pos(row, col, ThreeThree[i][j]):  # 判断row,col加上旋转后的坐标是否符合三三禁手
                        continue
                    else:
                        flag = False
                        break

                if i < len(ThreeThree_bank):
                    if flag == True:
                        for j in range(len(ThreeThree_bank) // 2):  # 判断三三禁手中活三两端的空格是否满足构成活三的条件
                            c = 0
                            if self.judge_the_pos_blank(row, col, ThreeThree_bank[i][c], ThreeThree_bank[i][c + 1]):
                                c += 2
                                continue
                            else:
                                flag = False
                                break
                        if flag == True:
                            return True
                else:
                    if flag == True:
                        return True

        return False

        # print(ThreeThree)

    def charge_four_forbid(self, row, col):  # 判断四四禁手
        FourFour = copy.deepcopy(self.FourFour)

        for i in range(len(FourFour)):
            for k in range(8):  # 旋转8次，每次逆时针选择45度

                flag = True

                for j in range(len(FourFour[i])):  # 符合四四禁手的坐标旋转
                    x = FourFour[i][j][0]
                    y = FourFour[i][j][1]
                    x1, y1 = self.get_spin_pos(x, y)
                    FourFour[i][j][0] = x1
                    FourFour[i][j][1] = y1

                for j in range(len(FourFour[i])):
                    if self.judge_the_pos(row, col, FourFour[i][j]):  # 判断row,col加上旋转后的坐标是否符合四四禁手
                        continue
                    else:
                        flag = False
                        break

                if flag == True:
                    return True

        return False

        # print(FourFour)

    def charge_long_forbid(self, row, col):  # 判断长连禁手
        LongLong = copy.deepcopy(self.LongLong)

        for i in range(len(LongLong)):
            for k in range(8):  # 旋转8次，每次逆时针选择45度

                for j in range(len(LongLong[i])):  # 符合长连禁手的坐标旋转
                    x = LongLong[i][j][0]
                    y = LongLong[i][j][1]
                    x1, y1 = self.get_spin_pos(x, y)
                    LongLong[i][j][0] = x1
                    LongLong[i][j][1] = y1

                flag = True

                for j in range(len(LongLong[i])):
                    if self.judge_the_pos(row, col, LongLong[i][j]):  # 判断row,col加上旋转后的坐标是否符合长连禁手
                        continue
                    else:
                        flag = False
                        break

                if flag == True:
                    return True

        return False

    def change_one_to_zero(self):  # 将[0,0,1]改成[0,0,0]

        ThreeThree = self.ThreeThree
        FourFour = self.FourFour
        LongLong = self.LongLong

        for i in range(len(ThreeThree)):
            ThreeThree[i][0][2] = 0

        for i in range(len(FourFour)):
            FourFour[i][0][2] = 0

        for i in range(len(LongLong)):
            LongLong[i][0][2] = 0

    def deal_noobrobot_move(self, row, col):  # 判断菜鸟机器人的下一步移动位置是否为禁手点

        self.change_one_to_zero()
        if self.charge_three_forbid(row, col):
            return True
        if self.charge_four_forbid(row, col):
            return True
        if self.charge_long_forbid(row, col):
            return True
        return False
