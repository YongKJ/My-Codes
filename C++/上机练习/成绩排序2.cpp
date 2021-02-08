#include <iostream>
#include <iomanip>
#include <vector>
#include<algorithm>
using namespace std;

typedef struct book1
{   
    int s1,s2,s3;
    int p,s4;
}book;

bool compare(const book &a,const book &b)
{    
    if (a.s4<b.s4) 
    return 1;
    else if (a.s4==b.s4)
    {
        if (a.s1<b.s1) 
        return 1;
        else if (a.s1==b.s1)
        {
            if (a.s2<b.s2) 
            return 1;
            else if (a.s2==b.s2)
            {
                if (a.s3<b.s3) 
                return 1;
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

int main()
{
    int n,i,t;
    cin>>t;n=t;
    vector <book> v;
    while (t--) {
      book bb;
      cin >> bb.p >> bb.s1 >> bb.s2 >> bb.s3;
      bb.s4 = bb.s1 + bb.s2 + bb.s3;
      v.push_back(bb);
    }
    sort(v.begin(), v.end(), compare);
    for (i = 0; i < n; i++)
      cout << v[i].p << " " << v[i].s4 << " " << v[i].s1 << " " << v[i].s2
           << " " << v[i].s3 << endl;
    v.clear();
    return 0;
}
/*Sample Input

4 
1001 70 80 90 
1002 60 70 80 
1003 80 90 70 
1004 70 85 85

Sample Output

1002 210 60 70 80 
1001 240 70 80 90 
1004 240 70 85 85 
1003 240 80 90 70
*/