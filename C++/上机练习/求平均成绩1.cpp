#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
class score{
public:
    int set_numbers();
    void set_score();
    void show_course_score();
    void show_student_score();
    void show_student_amount();
private:
    double sco[50][5],avg1[50],avg2[50],n,m;
    int stu;
};
int main(){
    score d1;
    while(d1.set_numbers()){
        d1.set_score();
        d1.show_course_score();
        d1.show_student_score();
        d1.show_student_amount();
    }
    return 0;
}
inline int score::set_numbers(){
    if(scanf("%lf%lf",&n,&m)!=EOF&&n<=50&&m<=5)
      return 1;
    else
    return 0;
}
inline void score::set_score(){
    for(int i=0;i<n;i++){
        avg1[i]=0;
        for(int j=0;j<m;j++){
            cin>>sco[i][j];
            avg1[i]+=sco[i][j];
        }
        avg1[i]/=m;
    }
}
inline void score::show_course_score(){
    for(int k=0,i=0;i<n;i++){
        if(k!=0)
        cout<<" ";
        cout<<fixed<<setprecision(2)<<avg1[i];
        k++;
    }
    cout<<endl;
}
inline void score::show_student_score(){
    for(int k=0,j=0;j<m;j++){
        avg2[j]=0;
        for(int i=0;i<n;i++)
        avg2[j]+=sco[i][j];
        avg2[j]/=n;
        if(k!=0)
        cout<<" ";
        cout<<fixed<<setprecision(2)<<avg2[j];
        k++;
    }
    cout<<endl;
}
inline void score::show_student_amount(){
    stu=0;
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<m;j++)
        if(sco[i][j]>=avg2[j])
        k++;
        if(k==m)
        stu++;
    }
    cout<<stu<<endl<<endl;
}