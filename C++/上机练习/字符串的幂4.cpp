#include<iostream>
using namespace std;

int getNext(char* arr, int len)     
{
	int* next = new int[len];
	memset(next, 0, len*sizeof(int));
	for (int i = 1; i < len; ++i)
	{
		int p = next[i - 1];
		while (p > 0 && arr[i] != arr[p])
			p = next[p - 1];
		if (p == 0 && arr[i] != arr[p]) 
			next[i] = 0;
		else next[i] = p + 1;
	}
	return next[len - 1];
}

int main()
{
	char arr[1000001] = { '\0' };
        while (scanf("%s", arr)) {
          int len = strlen(arr);
          int next = getNext(arr, len);
          if (len % (len - next) == 0)
            cout << len / (len - next) << endl;
          else
            cout << 1 << endl;
        }
}