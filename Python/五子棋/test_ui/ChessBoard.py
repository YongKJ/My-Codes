class ChessBoard(object):

    def __init__(self):  # 初始化棋盘矩阵
        self._board = [[0 for n in range(15)] for m in range(15)]

    def reset(self):  # 重置棋盘矩阵
        for i in range(15):
            for j in range(15):
                self._board[i][j] = 0

    def get_player_input(self):  # 返回输入数据
        data = input("Your move (u:undo, q:quit): ")
        return data

    def get_board(self):  # 返回棋盘矩阵
        return self._board

    def out_gobang_board(self, n, _board):  # 输出棋盘矩阵
        # print(_board)
        text = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O']
        t = "\n<round %d>\n  "
        for i in range(15):
            t += text[i]
            if i == 14:
                t += '\n'
            else:
                t += ' '
        for i in range(15):
            t += text[i] + ' '
            for j in range(15):
                if _board[i][j] == 0:
                    t += '.'
                elif _board[i][j] == 1:
                    t += '○'
                elif _board[i][j] == 2:
                    t += '●'
                if j == 14:
                    t += '\n'
                else:
                    t += ' '
        print(t % n, end='')

