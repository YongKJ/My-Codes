#include <iostream>
#include <cstdio>

using namespace std;
int js[1000001];
int t;
int n, a, b;
int main(){
    cin >> n >> t; 
    for(int i = 1; i <= n; ++i){
        cin >> a >> b;
        for (int j = t; j >= a; --j) {
          js[j] = max(js[j], js[j - a] + b);
        }
    }
    cout << js[t] << endl;
    return 0;
}