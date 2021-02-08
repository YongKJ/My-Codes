		self.POS = tuple(self.POS)
		for i in xrange(15):
			row = [ (7 - max(abs(i - 7), abs(j - 7))) for j in xrange(15) ]
			self.POS.append(tuple(row))
		self.POS = tuple(self.POS)
		self.STWO = 1		# 冲二
		self.STHREE = 2		# 冲三
		self.SFOUR = 3		# 冲四
		self.TWO = 4		# 活二
		self.THREE = 5		# 活三
		self.FOUR = 6		# 活四
		self.FIVE = 7		# 活五
		self.DFOUR = 8		# 双四
		self.FOURT = 9		# 四三
		self.DTHREE = 10	# 双三
		self.NOTYPE = 11	
		self.ANALYSED = 255		# 已经分析过
		self.TODO = 0			# 没有分析过
		self.result = [ 0 for i in xrange(30) ]		# 保存当前直线分析值
		self.line = [ 0 for i in xrange(30) ]		# 当前直线数据
		self.record = []			# 全盘分析结果 [row][col][方向]
		for i in xrange(15):
			self.record.append([])
			self.record[i] = []
			for j in xrange(15):
				self.record[i].append([ 0, 0, 0, 0])
		self.count = []				# 每种棋局的个数：count[黑棋/白棋][模式]
		for i in xrange(3):
			data = [ 0 for i in xrange(20) ]
			self.count.append(data)
		self.reset()


		#----------------------------------------------------------------------
# evaluation: 棋盘评估类，给当前棋盘打分用
#----------------------------------------------------------------------
class evaluation (object):

#----------------------------------------------------------------------
# DFS: 博弈树搜索
#----------------------------------------------------------------------
class searcher (object):