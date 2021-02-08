#include <iostream>
#include <string>
using namespace std;
static void check(int n, int index, int strNum[], string str[]);
int main(){
	static int n, num,**strNum;  
        static string str[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9",  
            "10", "J", "Q", "K", "J1", "J2" };
        cin >> n;
        for (int i = 0; i < n; i++) {  
            cin>>num;  
            string *Array= new string[num];  
  
           strNum = new int*[num];
           for (int l=0;l<num;l++)
             strNum[l] = new int[15];
            for (int j = 0; j < num; j++) {  
              cin>>Array[j];  
                for (int k = 0; k < 15; k++) {
                  if (Array[j]==str[k]) {
                    strNum[i][k]++;
                  }
                }
            }		
            check(num, i + 1, strNum[i], Array);
        }
}
 static void check(int n, int index, int strNum[], string str[]) {
   int tmp=0,n1 = 0, n2 = 0, n3 = 0,k1=0,k2=0,k3=0,k4=0;
        switch (n) {  
        case 1:  
            // 单张牌  
            cout<<"Case #" << index << ": Yes"<<endl;  
            break;  
        case 2:  
            // 一对或者是大小王  
            if ((str[1]=="J2" && str[0]=="J1")  
                    || str[0]==str[1] || (str[0]=="J2"
                    && str[1]=="J1")) {  
                cout<<"Case #" << index << ": Yes"<<endl;  
            } else  
                cout<<"Case #" << index << ": No"<<endl;  
            break;  
        case 3:  
            // 三张一样的牌  
            if (str[0]==str[1] && str[1]==str[2])  
                cout<<"Case #" << index << ": Yes"<<endl;  
            else  
                cout<<"Case #" << index << ": No"<<endl;  
            break;  
        case 4:  
            // 三带一或者炸弹  
            for (int k = 0; k < 13; k++) {  
                if (strNum[k] == 4 || strNum[k] == 3) {  
                    cout<<"Case #" << index << ": Yes"<<endl;  
                    return;  
                }  
            }  
            cout<<"Case #" << index << ": No"<<endl;  
            break;  
        case 5:  
            // 单顺  
            for (int i = 0; i < 10; i++) {  
                if (strNum[i] == 1 && strNum[i + 1] == 1 && strNum[i + 2] == 1  
                        && strNum[i + 3] == 1 && strNum[(i + 4) % 13] == 1) {  
                    cout<<"Case #" << index << ": Yes"<<endl;  
                    return;  
                }  
            }  
            // 3带2  
         //   int tmp = 0;  
            for (int i = 0; i < 13; i++) {  
                if (strNum[i] == 3 || strNum[i] == 2) {
                  tmp++;
                }  
            }  
            if (tmp == 2) {  
                cout<<"Case #" << index << ": Yes"<<endl;  
            } else {  
                cout<<"Case #" << index << ": No"<<endl;  
            }  
            break;  
        case 6:  
            // 单顺  
            for (int i = 0; i < 9; i++) {  
                if (strNum[i] == 1 && strNum[i + 1] == 1 && strNum[i + 2] == 1  
                        && strNum[i + 3] == 1 && strNum[i + 4] == 1  
                        && strNum[(i + 5) % 13] == 1) {  
                    cout<<"Case #" <<index <<": Yes"<<endl;
                    return;
                }  
            }  
           /* int n1 = 0;  
            int n2 = 0;  
            int n3 = 0;  */
            // 双顺或者三顺  
            for (int i = 0; i < 13; i++) {  
                if (strNum[i] == 3)  
                    n1++;  
                if (strNum[i] == 2)  
                    n2++;  
                if (strNum[i] == 4)  
                    n3++;  
            }  
            if (n3 == 1 || n1 == 2 || n2 == 3 || n2 == 3 || n1 == 2) {  
                cout<<"Case #" <<index << ": Yes"<<endl;  
            } else {  
                cout<<"Case #" << index << ": No"<<endl;  
            }  
            break;  
        default:  
            // 单顺  
         //   int k1 = 0;  
            // 双顺  
            //int k2 = 0;  
            //int k3 = 0;  
           // int k4 = 0;  
            for (int i = 0; i < 13; i++) {  
                if (strNum[i] == 1)  
                    k1++;  
                if (strNum[i] == 2)  
                    k2++;  
                if (strNum[i] == 3 && strNum[i + 1] == 3)  
                    k3++;  
                if (strNum[i] == 4)  
                    k4++;  
            }  
            if (k1 == n || k2 * 2 == n || (k3 + 1) * 3 == n  
                    || k2 * 2 + (k3 + 1) * 3 == n || k3 * 3 + k1 == n  
                    || k4 * 4 + k1 == n || k4 * 4 + k2 * 2 == n  
                    || (k3 + 1) * 3 + k1 == n) {  
                cout<<"Case #" << index << ": Yes"<<endl;  
            } else {  
                cout<<"Case #" << index << ": No"<<endl;  
            }  
            break;  
        }  
    }    