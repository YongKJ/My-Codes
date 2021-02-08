//贪心算法——最大整数
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;
string str[3] = {""};




string GetStrFromInt(int n)
{
stringstream ss;
string s;
ss << n;
ss >> s;
return s;
}




string GreedyAlgorithm(int n)
{
int arr[4] = { 0 };
string strmax = "";
cout << "Please Input the Data:" << endl;
int m = n;
while (m--)
{
if (!(cin >> arr[m]))
{
cout << "输入数据不合法" << endl;
return NULL;
}
}


//核心算法———将整数转为字符串，连接起来进行比较
for (int i = 0; i < n; ++i)
{
str[i] = GetStrFromInt(arr[i]);
}



for (int i = 0; i < n; ++i)
{
for (int j = i + 1; j < n; ++j)
{
if ((str[i]+str[j]).compare(str[j] + str[i]) < 0)
{
string temp=str[i];
str[i] = str[j];
str[j] = temp;
}
}
}
for (int i = 0; i < n; ++i)
{
strmax += str[i];
}
return strmax;
}

int main() {
  int n;
  cout << "Please Input Datas:" << endl;
  if (cin >> n)
    cout << GreedyAlgorithm(n) << endl;
  else
    cout << "输入数据不合法" << endl;
  return 0;
}