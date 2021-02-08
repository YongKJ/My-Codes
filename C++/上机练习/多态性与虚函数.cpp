#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Rational{
public:
    Rational(int p=0,int q=1);
    int operator < (Rational r) const;
    int operator <= (Rational r) const;
    int operator == (Rational r) const;
    int operator != (Rational r) const;
private:
    long num,den;
};
class Animal{
public:
    Animal(){name=NULL;}
    Animal(char *n);
    ~Animal(){delete name;}
    virtual void Idetify();
protected:
    char *name;
};
class Cat:public Animal{
public:
    Cat():Animal(){}
    Cat(char *n):Animal(n){}
    void Idetify();
};
class Dog:public Animal{
public:
    Dog():Animal(){}
    Dog(char *n):Animal(n){}
    void Idetify();
};
class Tiger:public Cat{
public:
    Tiger():Cat(){}
    Tiger(char *n):Cat(n){}
    void Idetify();
};
class Zoo{
public:
    Zoo(unsigned int max);
    ~Zoo(){delete residents;}
    unsigned int Accept(Animal *d);
    void ListAnimals();
private:
    unsigned int maxanimals;
    unsigned int numanimals;
    Animal **residents;
};
int main(){
    Rational x(2,3),y(3,4);
    if(x<y)
    cout<<"x<y"<<endl;
    else
    cout<<"x>y"<<endl;
    char p1[10]=" ";
    Animal a(p1);
    a.Idetify();
    char p2[10]="Herry";
    Cat cat(p2),*q;
    cat.Idetify();
    char p3[10]="Jimmy";
    Dog dog(p3),*p;
    dog.Idetify();
    char p4[10]="Richard";
    Tiger tiger(p4),*r;
    tiger.Idetify();
    Zoo beijing(20);
    q=&cat;
    p=&dog;
    r=&tiger;
    unsigned i=beijing.Accept(p);
    beijing.ListAnimals();
    i=beijing.Accept(q);
    beijing.ListAnimals();
    i=beijing.Accept(r);
    beijing.ListAnimals();
    return 0;
}
Rational::Rational(int p,int q):num(p),den(q){
    if(den==0){
    cout<<"A Zero denomination is invalid"<<endl;
    exit(1);
    }
}
int Rational::operator <(Rational r) const{
    return num*r.den<r.num*den;
}
int Rational::operator <=(Rational r) const{
    return num*r.den<=r.num*den;
}
int Rational::operator ==(Rational r) const{
    return num*r.den==r.num*den;
}
int Rational::operator !=(Rational r) const{
    return num*r.den!=r.num*den;
}
Animal::Animal(char *n){
    name=new char[strlen(n)+1];
    strcpy(name,n);
}
void Animal::Idetify(){
    cout<<"generic animal"<<endl;
}
void Cat::Idetify(){
    cout<<"I an a cat named "<<name<<"."<<endl;
}
void Dog::Idetify(){
    cout<<"I an a dog named "<<name<<"."<<endl;
}
void Tiger::Idetify(){
    cout<<"I an a cat named "<<name<<"."<<endl;
}
Zoo::Zoo(unsigned int max){
    maxanimals=max;
    numanimals=0;
    residents=new Animal *[maxanimals];
    for(int i=0;i<maxanimals;i++)
    residents[i]=NULL;
}
unsigned int Zoo::Accept(Animal *d){
    if(numanimals==maxanimals)
    return 0;
    ++numanimals;
    int i=0;
    while(residents[i]!=NULL)
    i++;
    residents[i]=d;
    return ++i;
}
void Zoo::ListAnimals(){
    cout<<endl<<"There are "<<numanimals<<" animals in zoo."<<endl;
    if(numanimals>0)
    for(int i=0;i<maxanimals;i++)
    if(residents[i]!=NULL)
    residents[i]->Idetify();
}
