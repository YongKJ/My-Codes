#include <iostream>
#include <set>
using namespace std;
class dou{					
public:
	dou();					
	int show();				
private:
	int n,s[15];
};
int main(){
	int n;
	cin>>n;
        for (int i = 1; i <= n; i++) {
          dou d1;
          cout << "Case #" << i << (d1.show() ? ": Yes" : ": No") << endl;
        }
	return 0;
}
dou::dou(){
	string str[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K","A","J1", "J2" },m;
	cin>>n;
	for(int i=0;i<15;i++)
		s[i]=0;
    for(int i=0;i<n;i++){	
    	cin>>m;
    	for(int i=0;i<15;i++)
          if (str[i] == m) {
            s[i]++;
            break;
          }
    }
}
int dou::show(){
	int one,two,three,four,one1,two1,three1,four1,a,b,c,t;
	set<int> x,y,z;												
	set<int>::iterator p,q;
	one=two=three=four=one1=two1=three1=four1=a=b=c=t=0;
        for (int i = 0; i < 13; i++) {
          if (s[i] == 1)
            one1++;
          else if (s[i] == 2)
            two1++;
          else if (s[i] == 3)
            three1++;
          else if (s[i] == 4)
            four1++;
        }
        for (int i = 1; i < 13; i++) {
          if (s[i] == 1)
            one++, x.insert(i);
          else if (s[i] == 2)
            two++, y.insert(i);
          else if (s[i] == 3)
            three++, z.insert(i);
          else if (s[i] == 4)
            four++;
        }
	p=x.begin(),q=x.end();
	if(p!=q)
		a=*(--q)-*p;											
	p=y.begin(),q=y.end();
	if(p!=q)
		b=*(--q)-*p;
	p=z.begin(),q=z.end();
	if(p!=q)
		c=*(--q)-*p;
        switch (n) {
        case 1:
          t = 1;
          break;
        case 2:
          t = (two1 == 1 || (s[13] == 1 && s[14] == 1)) ? 1 : 0;
          break;
        case 3:
          t = (three1 == 1) ? 1 : 0;
          break;
        case 4:
          t = (four1 == 1 || (three1 + one1 == 2)) ? 1 : 0;
          break;
        case 5:
          t = ((one == 5 && a + 1 == 5) || (three1 == 1 && two1 == 1)) ? 1 : 0;
          break;
        case 6:
          t = ((one == 6 && a + 1 == 6) || (two == 3 && b + 1 == 3) ||
               (three == 2 && c + 1 == 2) || (four1 == 1 && two1 == 1))
                  ? 1
                  : 0;
          break;
        default:
          t = ((one == n && a + 1 == n) ||
               (n % 2 == 0 && two == n / 2 && b + 1 == n / 2) ||
               (n % 3 == 0 && three == n / 3 && c + 1 == n / 3) ||
               (three == one1 && c + 1 == (n - one1) / 3) ||
               (three == two1 && c + 1 == (n - two1 * 2) / 3) ||
               (four1 == 1 && two1 == 2 && n == 8))
                  ? 1
                  : 0;
          break;
        }
		return t;
	}