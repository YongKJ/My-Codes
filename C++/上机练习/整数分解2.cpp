#include<iostream>
#include<vector>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        if (n <(k*(k + 1)) / 2)
        {
            cout << -1 << endl;
        }
        else
        {
            n = n - k*(k + 1) / 2;
            vector<long long> num(k + 1);
            for (int a = 1;a <= k;a++)
            {
                num[a] = (n / k) + a;
            }
            for (int a = k;a >k - n%k;a--)
            {
                num[a]++;
            }
            long long sum = 1;
            for (int a = 1; a <= k; a++) {
              sum = sum * num[a] % mod;
            }
            cout << sum % mod << endl;
        }
    }
    return 0;
}