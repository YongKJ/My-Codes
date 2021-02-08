#include <iostream>
#include <string>
using namespace std;
class Person{
public:
    void input();
    void output();
//private:
    int number;
    string name,sex;
    double salary;
};
class Teacher:public virtual Person{
public:
    int title;
    void input();
    void output();
    void pay();
private:
    int teacher_hours;
};
class Temporary_workers:public virtual Person{
public:
    Temporary_workers():hourlyPay(30){}
    void input();
    void pay();
private:
    double hourlyPay;
    int workingHours;
};
class Staff:public virtual Person{
public:
    Staff(){}
    void input();
    void output();
    void pay();
//private:
    int position;
};
class Staff_Teacher:public Staff,public Teacher{
public:
    Staff_Teacher(){}
    void input();
    void output();
    void pay();
};
int main(){
    Person d1;
    Teacher d2;
    Temporary_workers d3;
    Staff d4;
    Staff_Teacher d5;
    d1.input();
    d1.output();
    cout<<endl;
    d2.input();
    d2.output();
    d2.pay();
    cout<<endl;
    d3.input();
    d3.output();
    d3.pay();
    cout<<endl;
    d4.input();
    d4.output();
    d4.pay();
    cout<<endl;
    d5.input();
    d5.output();
    d5.pay();
    return 0;
}
void Person::input(){
    cout<<"工号：";
    cin>>number;
    cout<<"姓名：";
    cin>>name;
    cout<<"性别：";
    cin>>sex;
}
void Person::output(){
    cout<<"+-------------------------------------+"<<endl;
    cout<<"工号："<<number<<endl;
    cout<<"姓名："<<name<<endl;
    cout<<"性别："<<sex<<endl;
    cout<<"+-------------------------------------+"<<endl;
}
void Teacher::input(){
    Person::input();
    cout<<"课时：";
    cin>>teacher_hours;
    cout<<"1------教授"<<endl;
    cout<<"2------副教授"<<endl;
    cout<<"3------讲师"<<endl;
    cout<<"4------助教"<<endl;
    cout<<"请选择职称：";
    cin>>title;
}
void Teacher::output(){
    Person::output();
    cout<<"课时："<<teacher_hours<<endl;
    cout<<"职称：";
    switch (title) {
    case 1:cout<<"教授"<<endl;break;
    case 2:cout<<"副教授"<<endl;break;
    case 3:cout<<"讲师"<<endl;break;
    case 4:cout<<"助教"<<endl;break;
    default:break;
    }
}
void Teacher::pay(){
    switch (title) {
    case 1:salary=teacher_hours*150+5000;break;
    case 2:salary=teacher_hours*120+4000;break;
    case 3:salary=teacher_hours*100+3000;break;
    case 4:salary=teacher_hours*80+2000;break;
    default:break;
    }
    cout<<"工资："<<salary<<endl;
}
void Temporary_workers::input(){
    Person::input();
    cout<<"当月工作时数：";
    cin>>workingHours;
}
void Temporary_workers::pay(){
    salary=workingHours*hourlyPay;
    cout<<"当月薪水："<<salary<<endl;
}
void Staff::input(){
    Person::input();
    cout<<"1------院级"<<endl;
    cout<<"2------处级"<<endl;
    cout<<"3------科级"<<endl;
    cout<<"4-------一般工作人员"<<endl;
    cout<<"请选择职位：";
    cin>>position;
}
void Staff::output(){
    Person::output();
    switch(position){
    case 1:cout<<"职位：院级"<<endl;break;
    case 2:cout<<"职位：处级"<<endl;break;
    case 3:cout<<"职位：科级"<<endl;break;
    case 4:cout<<"职位：一般工作人员"<<endl;break;
    default:break;
    }
}
void Staff::pay(){
    switch(position){
    case 1:salary=8000;break;
    case 2:salary=6800;break;
    case 3:salary=6600;break;
    case 4:salary=5000;break;
    default:break;
    }
    cout<<"当月薪水： "<<salary<<endl;
}
void Staff_Teacher::input(){
    Teacher::input();
    cout<<"1------院级"<<endl;
    cout<<"2------处级"<<endl;
    cout<<"3------科级"<<endl;
    cout<<"4-------一般工作人员"<<endl;
    cout<<"请选择职位：";
    cin>>position;
}
void Staff_Teacher::output(){
    Teacher::output();
    switch(position){
    case 1:cout<<"职位：院级"<<endl;break;
    case 2:cout<<"职位：处级"<<endl;break;
    case 3:cout<<"职位：科级"<<endl;break;
    case 4:cout<<"职位：一般工作人员"<<endl;break;
    default:break;
    }
}
void Staff_Teacher::pay(){
    Staff::pay();
    Teacher::pay();
}
