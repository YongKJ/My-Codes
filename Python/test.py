import datetime
t = datetime.datetime(2019, 9, 3, 21, 30)
print(t)
"""
import time
st = time.gmtime()
print(st)
st = time.localtime()
print(st)
"""
"""
import time
print(time.time())
start = time.clock()
for i in range(100000):
	print(i **2) 
end = time.clock()
print(end - start)
"""
"""
class Vow(object):
	def __init__(self, text):
		self.text = text
	def __enter__(self):
		self.text = "I say:" + self.text
		return self
	def __exit__(self, exc_type, exc_value, traceback):
		self.text = self.text + "!"
with Vow("I'm fine") as myVow:
	print(myVow.text)
"""
"""
with open("new.txt", "w") as f:
	f.write("Hello world!")
print(f.closed)
"""
"""
f = open("test.txt", "w")
f.write("I like apple\n")
f.close
f = open("test.txt", "r")
content = f.readline()
print(content)
"""
"""
import time

time.sleep(10)
"""
"""
from time import *

sleep(10)
print("wake up")
"""
"""
import time
print(dir(time))
"""
"""
class SampleMore(object):
	def __call__(self, a):
		return a + 5
add_five = SampleMore()
print(add_five(2))
"""
"""
def gen():
	i = 0
	while i < 10000000:
		i = i + 1
		yield i
for i in gen():
	print(i)
"""
"""
for item in iter([1, 2]):
	print(item)
def gen():
	a = 100
	yield a
	a = a*8
	yield a
	yield 10000
for i in gen():
	print(i)

"""
"""
a = [2, 4, 3, 1]
print(a[0], a[1], a[2], a[3])
for i in range(4):
	for j in range(i+1, 4):
		if(a[i] > a[j]):
			a[i], a[j] = a[j], a[i]
			print(a[0], a[1], a[2], a[3])
"""
"""
a = "abc"
print(a.index("c"))
str = "Hello world"
sub = "world"
print(str.count(sub))
print(str.find(sub))
print(str.index(sub))
print(str.rfind(sub))
print(str.rindex(sub))
print(str.isalnum())
print(str.isalpha())
print(str.isdigit())
print(str.istitle())
print(str.isspace())
print(str.islower())
print(str.isupper())
#print(str.split([sep, [max]]))
#print(str.rsplit([sep, [max]]))
print(str.join(s))
print(str.strip([sub]))
print(str.replace(sub, new_sub))
print(str.capitalize())
print(str.lower())
print(str.upper())
print(str.swapcase())
print(str.title())
print(str.center(width))
print(str.ljust(width))
print(str.rjust(width))
"""
"""
a = (1, 3, 5)
print(a.count(5))
print(a.index(3))
"""
"""
a = [1, 2, 3, 5, 9.0, "Good", -1, True, False, "Bye"]
print(a.count(5))
print(a.index(3))
print()
a.append(6)
print(a.index(6))
#a.sort()
print(a.reverse())
print(a.pop())
print(a.remove(2))
print(a.insert(0, 9))
print(a.clear())
"""
"""
class HelpDemo(object):
	
	This is a demo for using help() on a class
	
	pass
print(help(HelpDemo))
"""
"""
a = [1, 2, 5, 3, 5]
print(type(a))
print(dir(list))
help(list)
"""
"""
class Bird(object):
	def chirp(self):
		print("make sound")
class Chicken(Bird):
	def chirp(self):
		super().chirp()
		print("ji")

bird   = Bird()
bird.chirp()

summer = Chicken()
summer.chirp()
"""
"""
class Bird(object):
	feather		 = True
	reproduction = "egg"
	def chirp(self, sound):
		print(sound)
class chicken(Bird):
	how_to_move = "walk"
	edible		= True
class Swan(Bird):
	how_to_move = "swim"
	edible		= False
summer = chicken()
print(summer.feather)
summer.chirp("ji")
"""
"""
class Bird(object):
	def chirp(self, sound):
		print(sound)
	def chirp_repeat(self, sound, n):
		for i in range(n):
			self.chirp(sound)
summer = Bird()
summer.chirp_repeat("ji", 10)
"""
"""
class Bird(object):
	def __init__(self, sound):
		self.sound = sound
		print("my sound is:", sound)
	def chirp(self):
		print(self.sound)
summer = Bird("ji")
summer.chirp()
"""
"""
class Bird(object):
	def chirp(self, sound):
		print(sound)
	def set_color(self, color):
		self.color = color
summer = Bird()
summer.set_color("yellow")
print(summer.color)
"""
"""
class Bird(object):
	feather = True
	reproduction = "egg"
	def chirp(self, sound):
		print(sound)
summer = Bird()
print(summer.reproduction)
summer.chirp("jijiji")
"""
"""
def gaussian_sum(n):
	if n==1:
		return 1
	else:
		return n+gaussian_sum(n-1)
print(gaussian_sum(100))
"""
"""
i=0
residual=500000
interest_tuple=(0.01,0.02,0.03,0.035)
repay=30000
while residual>0:
	i+=1
	print("第",i,"年还是要还钱")
	if i<=4:
		interest=interest_tuple[i-1]
	else:
		interest=0.05
	residual=residual*(interest+1)-repay
  print("第",i+1,"年终于换完了")
"""
"""
total=980000
if total>500000:
	print("总数超过50万")
	transaction_rate=0.01
else:
	print("总数不超过50万")
	transaction_rate=0.02
print(transaction_rate)

interest_tuple = (0.01, 0.02, 0.03, 0.035, 0.05)
total = 500000
for interest in interest_tuple: 
	repay = total * interest 
	print("每年的利息：",repay)

"""
"""
v="Vivian"
print(type(v))

example_tuple=(2,1.3,"love",5.6,9,12,False)
print(type(example_tuple))
print(example_tuple[0:6:2])
sliced=example_tuple[2:0:-1]
print(type(sliced))
print(sliced)
print(example_tuple[1:-1])


example_list=[True,5,"smile"]
print(type(example_list))
print(example_list[2])

nest_list=[1,[3,4,5]]
print(type(nest_list))
print(nest_list[1][2])

empty_list=[]
print(type(empty_list))
#empty_list[0]=3.0
print(empty_list)

example_dict={"tom":11,"sam":57,"lily":100}
print(type(example_dict))
example_dict["tom"]=30
example_dict["lilei"]=99
print(example_dict)
"""