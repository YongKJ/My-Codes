from urllib import request
import re
import MySQLdb

class MovieTop(object):

    def __init__(self):
        self.start = 0
        self.param = '&filter ='
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64)'}
        self.movie_list = []

    def get_page(self):
        try:
            url = 'https://movie.douban.com/top250?start=' + str(self.start)
            req = request.Request(url, headers = self.headers)
            response = request.urlopen(req)
            page = response.read().decode('utf-8')
            page_num = (self.start + 25) // 25
            print("正在抓取第" + str(page_num) + "页数据")
            self.start += 25
            return page
        except request.URLError as e:
            if hasattr(e, 'reason'):
                print('抓取失败，失败原因:', e.reason)

    def get_movie_info(self):
        pattern = re.compile( u'<div.*?class="item".*?'
	                        + u'<div.*?class="pic">.*?'
	                        + u'<div.*?class="info">.*?'
	                        + u'<span.*?class="title">(.*?)'
	                        + u'</span>.*?<span.*?class="title">(.*?)</span>.*?'
	                        + u'<span.*?class="other">(.*?)</span>.*?</a>.*?'
	                        + u'<div.*?class="bd">.*?<p.*?class="">.*?'
	                        + u'导演: (.*?)&nbsp;&nbsp;&nbsp;.*?<br>'
	                        + u'(.*?)&nbsp;/&nbsp;(.*?)&nbsp;/&nbsp;'
	                        + u'(.*?)</p>.*?<div.*?class="star">.*?'
	                        + u'<span.*?'
	                        + u'class="rating_num".*?property="v:average">'
	                        + u'(.*?)</span>.*?'
	                        + u'.*?<span>(.*?)人评价</span>.*?'
	                        + u'<p.*?class="quote">.*?'
	                        + u'<span.*?class="inq">(.*?)'
	                        + u'</span>.*?</p>', re.S)
        while self.start <= 225:
            page = self.get_page()
            movies = re.findall(pattern, page)
            for movie in movies:
                self.movie_list.append([
                                        movie[0],
                                        movie[1].lstrip('&nbsp;/&nbsp;'),
                                        movie[2].lstrip('&nbsp;/&nbsp;'),
                                        movie[3].lstrip('&nbsp;/&nbsp;'),
                                        movie[4],
                                        movie[5].lstrip(),
                                        movie[6],
                                        movie[7].rstrip(),
                                        movie[8],
                                        movie[9]])

    def insert_into_mysql(self):
        db         = MySQLdb.connect(host="localhost",port=3310,user="root", passwd="*Dxj1003746818",db="practice",charset='utf8')
        cursor     = db.cursor()
        insert_str = "insert into douban_comment(movieName," \
                          "movieForName,movieAlias,directorName,showYear," \
                          "makeCounty,movieType,movieScore,scoreNum,shortFilm) " \
                          " values('%s','%s','%s','%s','%s','%s','%s','%s'," \
                          "'%s','%s')"
        try:
            for movie in self.movie_list:
                insert_sql = insert_str % (
                    movie[0],
                    movie[1],
                    movie[2],
                    movie[3],
                    movie[4],
                    movie[5],
                    movie[6],
                    movie[7],
                    movie[8],
                    movie[9]
                )
                cursor.execute(insert_sql)
            print('插入数据成功')
        except Exception as e:
            print(e)
        finally:
            db.commit()
            db.close()

    def main(self):
        print('开始抓取数据')
        self.get_movie_info()
        self.insert_into_mysql()
        print('抓取完毕')

dou_ban_spider = MovieTop()
dou_ban_spider.main()