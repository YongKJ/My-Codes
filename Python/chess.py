import numpy as np
 
class game:
 
    def __init__(self, **kwargs):
        self.wight = int(kwargs.get('wight', 15))
        self.height = int(kwargs.get('height', 15))
        '''棋盘原型 self.graphic 操作就是修改该对象'''
        self.graphic = np.zeros((self.height, self.wight))
        self.current_player = 1
        self.finish = False
        self.count = 1
 
    def move(self, position):
        if position[0] > self.height or position[1] > self.wight:
            print('输入位置超过棋盘范围')
            return False
        if self.graphic[position[0], position[1]] != 0:
            print('请在空白位置输入')
            return False
        if self.current_player == 1:
            self.graphic[position[0], position[1]] = 1
        else:
            self.graphic[position[0], position[1]] = -1
        self.current_player *= -1
        return True
 
    def iswin(self, location):
        current_value = self.graphic[location[0], location[1]]
        '''竖'''
        max_point = 0
        for i in range(1, 6):
            if location[0]-i < 0 or self.graphic[location[0]-i, location[1]] != current_value:
                break
            max_point = i
        for j in range(1, 6):
            if max_point >= 4:
                return True
            if location[0]+j >= self.height or self.graphic[location[0]+j, location[1]] != current_value:
                break
            max_point += 1
        '''横'''
        max_point = 0
        for i in range(1, 6):
            if location[1] - i < 0 or self.graphic[location[0], location[1] - i] != current_value:
                break
            max_point = i
        for j in range(1, 6):
            if max_point >= 4:
                return True
            if location[1] + j >= self.wight or self.graphic[location[0], location[1] + j] != current_value:
                break
            max_point += 1
        '''左上至右下斜线'''
        max_point = 0
        for i in range(1, 6):
            if (location[0] - i < 0 or location[1] - i < 0) \
                    or self.graphic[location[0] - i, location[1] - i] != current_value:
                break
            max_point = i
        for j in range(1, 6):
            if max_point >= 4:
                return True
            if (location[0] + j >= self.height or location[1] + j >= self.wight)\
                    or self.graphic[location[0] + j, location[1] + j] != current_value:
                break
            max_point += 1
        '''左下至右上斜线'''
        max_point = 0
        for i in range(1, 6):
            if (location[0] + i >= self.height or location[1] - i < 0) \
                    or self.graphic[location[0] + i, location[1] - i] != current_value:
                break
            max_point = i
        for j in range(1, 6):
            if max_point >= 4:
                return True
            if (location[0] - j < 0 or location[1] + j >= self.wight) \
                    or self.graphic[location[0] - j, location[1] + j] != current_value:
                break
            max_point += 1
 
    def view(self):
        for x in range(9):
            print("{0:9}".format(x), end='')
        print('\r\n')
        for i in range(9):
            print("{0:4}".format(i), end='')
            for j in range(9):
                if self.graphic[i][j] == 1:
                    print('X'.center(9), end='')
                elif self.graphic[i][j] == -1:
                    print('O'.center(9), end='')
                else:
                    print('_'.center(9), end='')
            print('\r\n')
 
    def lines(self):
        for i in range(20):
            print('####', end='')
        print('\n', '现在是第%d步' % self.count)
        for i in range(20):
            print('####', end='')
        print('\n')
 
    def run(self):
        while not self.finish:
            self.view()
            if self.current_player == 1:
                location = input("Player1 move: ")
            else:
                location = input("Player2 move: ")
            try:
                location = [int(n) for n in location.split(" ")]
            except ValueError:
                print("输出错误", '\r\n')
                continue
 
            if not self.move(location):
                continue
            if self.iswin(location):
                if self.current_player == -1:  # move后就已经交换了玩家
                    print("Player1 win")
                else:
                    print("Player2 win")
                self.view()
                return
            self.view()
            self.lines()
            self.count += 1

a = game(wight = 9,height= 9)
a.run()