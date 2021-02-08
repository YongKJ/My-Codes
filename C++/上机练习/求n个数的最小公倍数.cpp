#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(a<b)
	{
		int time=a;
		a=b;
		b=time;
	}
	if(b==0)
	return a;
	else
	gcd(b,a%b);
}
int main()
{
	int a[100000],time,sum;
        while (cin >> time && time) {
          for (int i = 0; i < time; i++)
            cin >> a[i];
          sum = a[0] / gcd(a[0], a[1]) * a[1];
          for (int i = 2; i < time; i++)
            sum = sum / gcd(sum, a[i]) * a[i];
          cout << sum << endl;
        }
}
/*
Sample Input
2 4 6
3 2 5 7
 

Sample Output
12
70
*/