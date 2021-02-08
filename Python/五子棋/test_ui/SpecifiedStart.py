import ChessBoard
import MySQLdb
import random


class SpecifiedStart(object):
    def __init__(self):  # 初始化指定开局类型
        self.start_type = ""  # 斜指开局或直指开局
        self.start_name = ""  # 指定开局名称
        self.priority = []  # 指定开局的优先级
        self._incline = [  # 斜指开局类型
            "长星",
            "峡月",
            "恒星",
            "水月",
            "流星",
            "云月",
            "浦月",
            "岚月",
            "银月",
            "明星",
            "斜月",
            "名月",
            "彗星"
        ]
        self._incline_priority = [  # 斜指开局优先级
            "2 2",  # 长星（I1）：白子优势
            "1 3",  # 峡月（I2）：黑子必胜
            "1 3",  # 恒星（I3）：黑子必胜
            "1 3",  # 水月（I4）：黑子必胜
            "2 2",  # 流星（I5）：白子优势
            "1 3",  # 云月（I6）：黑子必胜
            "1 3",  # 浦月（I7）：黑子必胜
            "1 3",  # 岚月（I8）：黑子必胜
            "1 2",  # 银月（I9）：黑子优势
            "1 3",  # 明星（I10）：黑子必胜
            "1 1",  # 斜月（I11）：黑子偏优
            "1 2",  # 名月（I12）：黑子优势
            "2 3"  # 彗星（I13）：白子必胜
        ]
        self._straight = [  # 直指开局类型
            "寒星",
            "溪月",
            "疏星",
            "花月",
            "残月",
            "雨月",
            "金星",
            "松月",
            "丘月",
            "新月",
            "瑞星",
            "山月",
            "游星"
        ]
        self._straight_priority = [  # 直指开局优先级
            "1 3",  # 寒星（D1）：黑子必胜
            "1 3",  # 溪月（D2）：黑子必胜
            "2 1",  # 疏星（D3）：白子偏优
            "1 3",  # 花月（D4）：黑子必胜
            "1 2",  # 残月（D5）：黑子优势
            "1 3",  # 雨月（D6）：黑子必胜
            "1 3",  # 金星（D7）：黑子必胜
            "1 2",  # 松月（D8）：黑子优势
            "1 1",  # 丘月（D9）：黑子偏优
            "1 3",  # 新月（D10）：黑子必胜
            "0 0",  # 瑞星（D11）：平衡
            "1 2",  # 山月（D12）：黑子优势
            "2 3"  # 游星（D13）：白子必胜
        ]

    def write_info_to_database(self, _board, filename, s):  # 写入开局信息到文件
        with open(filename, "w", encoding='utf-8') as f:
            s += "\n"
            for i in range(15):
                for j in range(15):
                    s += str(_board[i][j])
                    if j == 14:
                        s += "\n"
                    else:
                        s += " "
            f.write(s)

    def read_info_form_database(self, filename):  # 从文件读取开局信息
        with open(filename, "r", encoding='utf-8') as f:
            s = f.read().splitlines()
            del s[0]
        for i in range(len(s)):
            s[i] = s[i].split(' ')
        UI = ChessBoard.ChessBoard()
        UI.my_s(1, s)

    def create_inclined(self):  # 13种斜指开局，创建文件
        for i in range(13):
            _board = [[0 for n in range(15)] for m in range(15)]
            _board[7][7] = 1
            _board[6][8] = 2
            filename = "database\\inclined\\"
            filename += self._incline[i] + ".txt"
            self.write_info_to_database(_board, filename, str(self._incline_priority[i]))

    def create_straight(self):  # 13种直指开局，创建文件
        for i in range(13):
            _board = [[0 for n in range(15)] for m in range(15)]
            _board[7][7] = 1
            _board[6][7] = 2
            filename = "database\\straight\\"
            filename += self._straight[i] + ".txt"
            self.write_info_to_database(_board, filename, str(self._straight_priority[i]))

    def insert_inclined(self):  # 13种斜指开局信息存放到数据库
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "insert into inclined values ('%s', '%s', '%s')"
        for i in range(13):
            filename = "database\\inclined\\"
            filename += self._incline[i] + ".txt"
            with open(filename, "r", encoding='utf-8') as f:
                board = f.readlines()
            del board[0]
            insert_sql = insert_str % (
                self._incline[i],
                self._incline_priority[i],
                ''.join(board)
            )
            cursor.execute(insert_sql)
        db.commit()
        db.close()

    def insert_straight(self):  # 13种直指开局信息存放到数据库
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "insert into straight values ('%s', '%s', '%s')"
        for i in range(13):
            filename = "database\\straight\\"
            filename += self._straight[i] + ".txt"
            with open(filename, "r", encoding='utf-8') as f:
                board = f.readlines()
            del board[0]
            insert_sql = insert_str % (
                self._straight[i],
                self._straight_priority[i],
                ''.join(board)
            )
            cursor.execute(insert_sql)
        db.commit()
        db.close()

    def insert_all_to_db(self):  # 将全部棋局保存到数据库
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "insert into gobang_regular_board VALUES ('%d','%s','%s','%s','%s')"
        for i in range(13):
            filename = "database\\inclined\\"
            filename += self._incline[i] + ".txt"
            with open(filename, "r", encoding='utf-8') as f:
                board = f.readlines()
            del board[0]
            insert_sql = insert_str % (
                i + 1,
                "inclined",
                self._incline[i],
                self._incline_priority[i],
                ''.join(board)
            )
            cursor.execute(insert_sql)

        for i in range(13):
            filename = "database\\straight\\"
            filename += self._straight[i] + ".txt"
            with open(filename, "r", encoding='utf-8') as f:
                board = f.readlines()
            del board[0]
            insert_sql = insert_str % (
                i + 14,
                "straight",
                self._straight[i],
                self._straight_priority[i],
                ''.join(board)
            )
            cursor.execute(insert_sql)

        db.commit()
        db.close()

    def random_read_db(self):  # 从数据库中随机读取26种开局信息
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "select * from %s where name='%s'"

        type_num = random.randint(1, 2)
        name_num = random.randint(0, 12)

        if type_num == 1:
            type_str = "inclined"
            name_str = self._incline[name_num]
        else:
            type_str = "straight"
            name_str = self._straight[name_num]
        self.start_type = type_str
        self.start_name = name_str

        insert_sql = insert_str % (
            type_str,
            name_str
        )
        cursor.execute(insert_sql)

        for row in cursor:
            self.priority = row[1].split(' ')
            board = row[2].split('\n')
            del board[len(board) - 1]

            for i in range(len(board)):
                board[i] = board[i].split(' ')
        db.commit()
        db.close()
        return self.gobang_board_str_to_int(board)

    def hand_read_db(self):  # 从数据库中手动读取26种开局信息
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "select * from %s where name='%s'"

        print("请选择斜指或直指开局(输入数字1选择斜指开局，输入数字2选择直指开局):")
        type_num = int(input())

        if type_num == 1:
            out_str = ""
            for i in range(13):
                out_str += str(i + 1) + '.' + self._incline[i]
                if i == 12 or i == 5:
                    out_str += '\n'
                else:
                    out_str += ' '
            print(out_str)
            print("请输入棋局的编号:")
            name_num = int(input())

            type_str = "inclined"
            name_str = self._incline[name_num - 1]

        else:
            out_str = ""
            for i in range(13):
                out_str += str(i + 1) + '.' + self._straight[i]
                if i == 12 or i == 5:
                    out_str += '\n'
                else:
                    out_str += ' '
            print(out_str)
            print("请输入棋局的编号:")
            name_num = int(input())

            type_str = "straight"
            name_str = self._straight[name_num - 1]

        self.start_type = type_str
        self.start_name = name_str

        insert_sql = insert_str % (
            type_str,
            name_str
        )
        cursor.execute(insert_sql)

        for row in cursor:
            self.priority = row[1].split(' ')
            board = row[2].split('\n')
            del board[len(board) - 1]

            for i in range(len(board)):
                board[i] = board[i].split(' ')

        db.commit()
        db.close()

        return self.gobang_board_str_to_int(board)

    def gobang_board_str_to_int(self, board):  # 棋盘矩阵由字符型转换为整型
        for i in range(15):
            for j in range(15):
                board[i][j] = int(board[i][j])
        return board

    def get_start_type(self):
        return self.start_type

    def get_start_name(self):  # 返回指定开局的名称
        return self.start_name

    def get_priority(self):  # 返回指定开局的优先级
        return self.priority

