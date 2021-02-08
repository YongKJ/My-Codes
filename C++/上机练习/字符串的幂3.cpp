#include<iostream>
using namespace std;
typedef unsigned long long ull; 

char arr[1000001];
ull nbase[1000001];
ull Hash[1000001];
int base = 31;

int main()
{
	nbase[0] = 1;
	for (int i = 1; i < 1000001; ++i)
		nbase[i] = nbase[i - 1] * base;
	while (scanf("%s", arr))
	{
		int len = strlen(arr);
		ull n = 0;
		Hash[len] = 0;
		for (int i = len - 1; i >= 0; --i)
			Hash[i] = Hash[i + 1] * base + arr[i] - 'a' + 1;
		for (int k = 1; k <= len; ++k)
		{
			if (len%k != 0) continue;
			ull temp = Hash[0] - Hash[k] * nbase[k];
			int j = 0;
			for (j = k; j < len; j = j + k)
			{
				if (temp != Hash[j] - Hash[j + k] * nbase[k]) break;
				else temp = Hash[j] - Hash[j + k] * nbase[k];
			}
                        if (j == len) {
                          n = len / k;
                          break;
                        }
                }
                cout << n;
        }
}