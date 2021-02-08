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
    cout<<"���ţ�";
    cin>>number;
    cout<<"������";
    cin>>name;
    cout<<"�Ա�";
    cin>>sex;
}
void Person::output(){
    cout<<"+-------------------------------------+"<<endl;
    cout<<"���ţ�"<<number<<endl;
    cout<<"������"<<name<<endl;
    cout<<"�Ա�"<<sex<<endl;
    cout<<"+-------------------------------------+"<<endl;
}
void Teacher::input(){
    Person::input();
    cout<<"��ʱ��";
    cin>>teacher_hours;
    cout<<"1------����"<<endl;
    cout<<"2------������"<<endl;
    cout<<"3------��ʦ"<<endl;
    cout<<"4------����"<<endl;
    cout<<"��ѡ��ְ�ƣ�";
    cin>>title;
}
void Teacher::output(){
    Person::output();
    cout<<"��ʱ��"<<teacher_hours<<endl;
    cout<<"ְ�ƣ�";
    switch (title) {
    case 1:cout<<"����"<<endl;break;
    case 2:cout<<"������"<<endl;break;
    case 3:cout<<"��ʦ"<<endl;break;
    case 4:cout<<"����"<<endl;break;
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
    cout<<"���ʣ�"<<salary<<endl;
}
void Temporary_workers::input(){
    Person::input();
    cout<<"���¹���ʱ����";
    cin>>workingHours;
}
void Temporary_workers::pay(){
    salary=workingHours*hourlyPay;
    cout<<"����нˮ��"<<salary<<endl;
}
void Staff::input(){
    Person::input();
    cout<<"1------Ժ��"<<endl;
    cout<<"2------����"<<endl;
    cout<<"3------�Ƽ�"<<endl;
    cout<<"4-------һ�㹤����Ա"<<endl;
    cout<<"��ѡ��ְλ��";
    cin>>position;
}
void Staff::output(){
    Person::output();
    switch(position){
    case 1:cout<<"ְλ��Ժ��"<<endl;break;
    case 2:cout<<"ְλ������"<<endl;break;
    case 3:cout<<"ְλ���Ƽ�"<<endl;break;
    case 4:cout<<"ְλ��һ�㹤����Ա"<<endl;break;
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
    cout<<"����нˮ�� "<<salary<<endl;
}
void Staff_Teacher::input(){
    Teacher::input();
    cout<<"1------Ժ��"<<endl;
    cout<<"2------����"<<endl;
    cout<<"3------�Ƽ�"<<endl;
    cout<<"4-------һ�㹤����Ա"<<endl;
    cout<<"��ѡ��ְλ��";
    cin>>position;
}
void Staff_Teacher::output(){
    Teacher::output();
    switch(position){
    case 1:cout<<"ְλ��Ժ��"<<endl;break;
    case 2:cout<<"ְλ������"<<endl;break;
    case 3:cout<<"ְλ���Ƽ�"<<endl;break;
    case 4:cout<<"ְλ��һ�㹤����Ա"<<endl;break;
    default:break;
    }
}
void Staff_Teacher::pay(){
    Staff::pay();
    Teacher::pay();
}
