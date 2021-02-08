#include <iostream>
using namespace std;
void write(char *s);
int main()
{
	char a[]="Hello,world!";
	write(a);
}
void write(char *s)
{
	cout<<s;
}