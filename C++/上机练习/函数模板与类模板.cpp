#include <iostream>
using namespace std;
template <typename T>
void bubble(T *Array,int size){
	T temp;
	for(int i=0;i<size;i++)
		for(int j=0;j<size-i;j++)
			if(*(Array+j)>*(Array+j+1)){
				temp=*(Array+j);
				*(Array+j)=*(Array+j+1);
				*(Array+j+1)=temp;
			}
}
template <class Type>
class node{
	public:
		Type data;
		node<Type> *next;
};
template <class Type>
class Stacklink{
	public:
		Stacklink();
		~Stacklink();
		void push(Type value);
		Type pop();
		int isnull();
	private:
		node<Type> *top;
};
int main(){
	int a[10]={2,69,5,-89,99,64,38,12345,-9999,66};
	double d[8]={2.69,5.698741,-89.0,3.14159,32.1,456.781,1.0,-9999.123456789};
	bubble(a,10);
	for(int i=0;i<10;i++)
		cout<<" "<<a[i];
	cout<<endl;
	bubble(d,8);
	for(int i=0;i<8;i++)
		cout<<" "<<d[i];
	cout<<endl;
	int l=1,octal=0;
	long decimal,j;
	cout<<endl<<"Please input integer:";
	cin>>decimal;
	j=decimal;
	Stacklink<int> ss;
	while(j!=0){
		ss.push(j%8*l);
		j/=8;
		l*=10;
	}
	cout<<endl;
	while(!ss.isnull()){
		j=ss.pop();
		octal+=j;
	}
	cout<<octal<<endl;
	return 0;
}
template <class Type>
Stacklink<Type>::Stacklink(){
	node<Type> *T;
	T=new node<Type>;
	T->next=NULL;
	top=T;
}
template <class Type>
Stacklink<Type>::~Stacklink(){
	node<Type> *N,*Temp;
	for(N=top;N!=NULL;){
		Temp=N;
		N=N->next;
		delete Temp;
	}
}
template <class Type>
void Stacklink<Type>::push(Type value){
	node<Type> *T;
	T=new node<Type>;
	if(T!=NULL){
		T->next=top;
		T->data=value;
		top=T;
	}
	else{
		cout<<"assigned failure!";
		exit(1);
	}
}
template <class Type>
int Stacklink<Type>::isnull(){
	if(top->next==NULL)
		return 1;
	else
		return 0;
}
template <class Type>
Type Stacklink<Type>::pop(){
	Type value;
	node<Type> *Temp;
	if(top->next==NULL){
		cout<<endl<<"The stack is Null!"<<endl;
		return 0;
	}
	value=top->data;
	Temp=top;
	top=top->next;
	delete Temp;
	return value;
}





	
