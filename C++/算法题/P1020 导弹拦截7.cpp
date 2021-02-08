#include <iostream>
using namespace std;
const int MAX = 20;
bool prove(int arr[]);
void solution(int arr[],int *a,int *b);   //a为拦截数,b为需要设备数
int main()
{
    int arr[MAX] = {0} , i = 0,a = 0,b = 0;
    cout << "输入导弹高度:(输入0结束) " << endl;
    do
    {
        cin >> arr[i];
        i++;
    }while(arr[i-1] != 0 && i<MAX); 
    solution(arr,&a,&b);
    cout << "一套设备能够拦截的导弹数是: " << a << endl;
    cout << "拦截全部导弹需要的设备数是: " << b << endl;
    system("pause");
    return 0;
}
bool prove(int arr[])
{
    for(int i = 0;i<MAX;i++)
    {
        if ( arr[i] != 0) 
        {
            return true;
        }
    }
    return false;
}
void solution(int arr[],int *a,int *b)  //输入输出参数，通过引用调用 
{
    do
    {
        int min = 0;
        for(int i=0;i<MAX;i++)
        {
            if(arr[i] != 0)
            {
                min = arr[i];   
                arr[i] = 0;
                break;   //直接跳出for循环，不是中止一次！！！ 
            }
        }
      
        for(int i=0;i<MAX;i++)
        {
            if(arr[i] < min && arr[i] != 0 )  //求最长不将序列长度 
            {
                min = arr[i];
                arr[i] = 0;
                (*a)++;     //从i=N方案到i=0方案的求和;递归方案
            }
        }
        (*b)++;
    }while(prove(arr));
    return;
}
/*
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够达到任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，
雷达捕捉到敌国的导弹来袭。由于该系统还在使用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。 
输入导弹依次飞来的高度（雷达给出高度数据是不大于30000的正整数），计算这套系统最多能拦截多少导弹，
如果要拦截所有导弹最少要配备多少套这种导弹系统。
样例：
  Input:   389   207     155     300     299     170     158     65
Output:   6(最多拦截导弹数)
         2（要拦截所有导弹最少要配备的系统数）
很早就看到这个经典的题目，但是一直没有把它的代码出来。一开始的思路是动态规划，步步最优结果最优。开始，我尝试着从后面倒序计算，因为后面的计算要用到前面的结果，所以用数组存储从后面计算的结果，结果越写到后面感觉越乱，越写越复杂。最后还是顺着我的思路写完了。
后来我上网一查才知道，设计的算法不合理，没有充分理解动态规划的解决问题的思想。然后。。。重新认真的分析，参考。。。才明白，子问题和原问题的解间有联系，只需要解决子问题，最后再累加，就问得到原问题的解。。。。
应该好好去理解动态规划。。。
*/