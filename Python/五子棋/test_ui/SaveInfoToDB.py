# coding=gbk

import MySQLdb
import copy
import queue


class SaveInfoToDB(object):

    def __init__(self):
        self.a = [0, 1]

    def board_stack_to_str(self, board_stack):  # 棋盘矩阵堆栈转字符串
        insert_str = ""
        while not board_stack.empty():
            board = board_stack.get()
            for i in range(15):
                for j in range(15):
                    insert_str += str(board[i][j])
                    if j == 14:
                        insert_str += '\n'
                    else:
                        insert_str += ' '
            if board_stack.qsize() != 0:
                insert_str += "#\n"

        return insert_str

    def move_stack_to_str(self, move_stack):  # 移动位置的坐标队列矩阵堆栈转字符串
        insert_str = ""
        while not move_stack.empty():
            move = move_stack.get()
            for i in range(2):
                insert_str += str(move[i])
                if i == 1:
                    insert_str += '\n'
                else:
                    insert_str += ' '
        return insert_str

    def Save_regular_start_info_to_db(self, robot_type, opening_type, five_step_choose, five_step_num,  # 指定开局存入数据库
                                      three_step_change, regular_start_type, regular_start_name, regular_start_priority,
                                      robot_move_stack, player_move_stack,
                                      gobang_board_stack):
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "insert into gobang_info(robot_type, player_type, opening_type, five_step_choose, five_step_num, three_step_change," \
                     " regular_start_type, regular_start_name, regular_start_priority, robot_move_stack, player_move_stack, gobang_board_stack)" \
                     " values ('%d','%d','%d', '%d','%d','%d','%s','%s','%s', '%s','%s','%s')"
        if robot_type == 1:
            player_type = 2
        else:
            player_type = 1
        if five_step_choose == True:
            five_step_choose = 1
        else:
            five_step_choose = 0
        if three_step_change == True:
            three_step_change = 1
        else:
            three_step_change = 0
        regular_start_priority_str = ""
        regular_start_priority_str += str(regular_start_priority[0]) + ' ' + str(regular_start_priority[1])
        insert_sql = insert_str % (
            robot_type,
            player_type,
            opening_type,
            five_step_choose,
            five_step_num,
            three_step_change,
            regular_start_type,
            regular_start_name,
            regular_start_priority_str,
            self.move_stack_to_str(robot_move_stack),
            self.move_stack_to_str(player_move_stack),
            self.board_stack_to_str(gobang_board_stack)
        )
        cursor.execute(insert_sql)
        db.commit()
        db.close()

    def Save_free_start_info_to_db(self, robot_type, opening_type, robot_move_stack, player_move_stack,  # 自由开局存入数据库
                                   gobang_board_stack):
        db = MySQLdb.connect(host="localhost", port=3307, user="root", passwd="*Dxj1003746818", db="gobang",
                             charset="utf8")
        cursor = db.cursor()
        insert_str = "insert into gobang_info(robot_type, player_type, opening_type, robot_move_stack, player_move_stack, gobang_board_stack)" \
                     " values ('%d','%d','%d','%s','%s','%s')"
        if robot_type == 1:
            player_type = 2
        else:
            player_type = 1
        insert_sql = insert_str % (
            robot_type,
            player_type,
            opening_type,
            self.move_stack_to_str(robot_move_stack),
            self.move_stack_to_str(player_move_stack),
            self.board_stack_to_str(gobang_board_stack)
        )
        cursor.execute(insert_sql)
        db.commit()
        db.close()
