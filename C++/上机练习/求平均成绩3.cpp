#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
	int n,m;
	int grade[55][6];
	double student[55];
	double course[6];
	while(cin>>n>>m){
		memset(grade,0,sizeof(grade));
		memset(course,0,sizeof(course));
		memset(student,0,sizeof(student));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>grade[i][j];
			}
		}
		
		//求每门课程的平均成绩 
		for(int i=1;i<=m;i++){
			double sum=0;
			for(int j=1;j<=n;j++){
				sum+=grade[j][i];
			}
			course[i]=sum/n;
	
		}
		
		//求每个学生的平均成绩 
		for(int i=1;i<=n;i++){
			double sum=0;
			for(int j=1;j<=m;j++){
				sum+=grade[i][j];
			}
			student[i]=sum/m;
		}
		
		//求各科成绩均大于等于平均成绩的学生数量
		int count=0;
		for(int i=1;i<=n;i++){
			int mark=1;
			for(int j=1;j<=m;j++){
				if(grade[i][j]<course[j]){
					mark=0;
					break;
				}
				
			} 
			if(mark==1){
				count++;
			}
		}
		//注意输出格式 
		for(int i=1;i<=n;i++){
			if(i==1){
				printf("%.2lf",student[i]);
			}
			else{
				printf(" %.2lf",student[i]);
			}
			
		}	
		cout<<endl;
		for(int i=1;i<=m;i++){
			if(i==1){
				printf("%.2lf",course[i]);
                        } else {
                          printf(" %.2lf", course[i]);
                        }
                }
                cout << endl;
                //两个回车
                cout << count << endl << endl;
        }

        return 0;
}