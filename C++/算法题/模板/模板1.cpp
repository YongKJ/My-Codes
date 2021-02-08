#include<iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE	100

typedef int Status;
typedef char SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//栈的初始化
Status InitStack(SqStack &S)
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}

//入栈
Status Push(SqStack &S, SElemType e)
{
	if(S.top-S.base==S.stacksize)
		return ERROR;
	else
	{
		*(S.top++)=e;
		return OK;
	}
}

//出栈
Status Pop(SqStack &S, SElemType &e)
{
	if(S.base==S.top)
		return ERROR;
	else
	{
		e=*(S.top--);
		return OK;
	}
}

int main()
{
	SqStack s;
	int choose, flag=0;
	SElemType j, e, t;
	cout<<"1：初始化"<<endl;
	cout<<"2：入栈"<<endl;
	cout<<"3：出栈"<<endl;
	cout<<"0：结束"<<endl;

	choose=-1;
	while(choose!=0)
	{
		cout<<"请选择:";
		cin>>choose;
		switch(choose)
		{
		case 1:
			if(InitStack(s))
			{
				flag=1;
				cout<<"成功对栈进行初始化"<<endl;
			}
			else
				cout<<"初始化失败"<<endl;
			break;

		case 2:
			{
				fstream file;
				file.open("SqStack.txt");

				if(!file)
				{
					cout<<"未找到文件"<<endl;
					exit(ERROR);
				}

				if(flag)
				{
					flag=1;
					cout<<"进栈元素依次为:"<<endl;
					while(!file.eof())
					{
						file>>j;
						if(file.fail())
							break;
                                                else {
                                                  Push(s, j);
                                                  cout << j << " ";
                                                }
                                        }
                                        cout << endl;
                                }

                                else
                                  cout << "栈未创建" << endl;

                                file.close();
                } break;

                case 3:
                  cout << "依次弹出的栈顶元素为:" << endl;
                  while (Pop(s, t))
                    cout << t << " ";
                  flag = -1;
                  cout << endl;
                  break;
                }
        }
        return 0;
}