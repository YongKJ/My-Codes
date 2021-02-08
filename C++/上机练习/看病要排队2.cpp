#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<queue>  
using namespace std;  
  
struct Patient    
{    
    //值  
    int priority;  
    //编号  
    int key;    
    //重载操作符  
    friend bool operator < (Patient p1,Patient p2)    
    {      
        if(p1.priority != p2.priority){  
            return p1.priority < p2.priority;  
        }  
        else{  
            return p1.key > p2.key;  
        }  
    }  
};  
  
int main(){  
    int i,N,k;  
    char Type[4];  
    int DoctorID,PatientID;  
    Patient patient[2001];  
    while(scanf("%d",&N) != EOF){  
        //定义三个医生  
        priority_queue<Patient> Doctor1;  
        priority_queue<Patient> Doctor2;  
        priority_queue<Patient> Doctor3;  
        k = 1;  
        while(N--){  
            scanf("%s",Type);  
            //诊治  
            if(strcmp(Type,"IN") == 0){  
                //输入病人和医生  
                patient[k].key = k;  
                scanf("%d %d",&DoctorID,&patient[k].priority);  
                //排队  
                if(DoctorID == 1){  
                    Doctor1.push(patient[k]);  
                }  
                else if(DoctorID == 2){  
                    Doctor2.push(patient[k]);  
                }  
                else{  
                    Doctor3.push(patient[k]);  
                }  
                k++;  
            }  
            //出院  
            else if(strcmp(Type,"OUT") == 0){  
                //医生DoctorID进行了一次诊治，诊治完毕后，病人出院  
                scanf("%d",&DoctorID);  
                //医生1  
                if(DoctorID == 1){  
                    if(Doctor1.empty()){  
                        printf("EMPTY\n");  
                    }  
                    else{  
                        printf("%d\n",Doctor1.top().key);  
                        //出院  
                        Doctor1.pop();  
                    }  
                }  
                //医生2  
                else if(DoctorID == 2){  
                    if(Doctor2.empty()){  
                        printf("EMPTY\n");  
                    }  
                    else{  
                        printf("%d\n",Doctor2.top().key);  
                        //出院  
                        Doctor2.pop();  
                    }  
                }  
                //医生3  
                else{  
                    if(Doctor3.empty()){  
                        printf("EMPTY\n");  
                    }  
                    else{  
                        printf("%d\n",Doctor3.top().key);  
                        //出院  
                        Doctor3.pop();  
                    }  
                }  
            }  
        }  
    }  
    return 0;  
}  