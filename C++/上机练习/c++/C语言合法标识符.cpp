#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class Biaoshi{
public:
	void set_str();
	void disp_result();
	
private:
	char str[60];
	int number(char x);
	int character(char x);
	int line(char x);
}; 
int main()
{
	Biaoshi d1;
	int t;
	cin>>t;
	while(t--){
	d1.set_str();
	d1.disp_result();
	}
	return 0;
}
void Biaoshi::set_str(){
	int i=0,ch;
	memset(str,0,sizeof(str));
	getchar();
	while((ch=getchar())!='\n'){
		str[i++]=ch;
		}
		str[i]='\0';
}
void Biaoshi::disp_result(){
	int a=0,b=0;
	char c='\0',d=' ';
	if(character(str[0])||line(str[0]))
	a=1;
	for(int i=1;i<strlen(str);i++){
	if(character(str[i])||line(str[i])||number(str[i]))
	b=1;
	else
	{
	b=0;
	break;
	}
	}
	if(a&&b)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
}
int Biaoshi::number(char x){
	if(x>='0'&&x<='9')
	return 1;
	else
	return 0;
}
int Biaoshi::character(char x){
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
	return 1;
	else
	return 0;
}
int Biaoshi::line(char x){
	if(x=='_'&&x!=' ')
	return 1;
	else
	return 0;
}