import os
import pandas as pd
import requests
PATH = "C:/Users/Administrator/Desktop/iris/"
r = requests.get('https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data')
with open(PATH + 'iris.data', 'w') as f:
    f.write(r.text) 
os.listdir(PATH)
os.chdir(PATH)
df = pd.read_csv(PATH + 'iris.data', names=["sepal length", "sepal width", "petal length", "petal width", "class"])
df.head()
"""
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

X = np.linspace(-np.pi,np.pi,256,endpoint=True)
C,S =np.cos(X),np.sin(X) 

plt.plot(X,C)
plt.plot(X,S)
plt.show()
"""
"""
import requests
 
r = requests.get(url='http://www.itwhy.org')    # 最基本的GET请求
print(r.status_code)    # 获取返回状态
r = requests.get(url='http://dict.baidu.com/s', params={'wd':'python'})   #带参数的GET请求
print(r.url)
with open("test.html", 'w', encoding='utf-8') as f:	
	f.write(r.text)
print(r.text)   #打印解码后的返回数据
"""