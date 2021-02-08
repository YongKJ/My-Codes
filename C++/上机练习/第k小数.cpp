#include<iostream>
using namespace std;
void QuickSort(int arr[],int l,int r)
{
    if (l>=r)
    {
        return;
    }
    int i = l;
    int j = r;
    int v = arr[i];
    while (i<j)
    {
        while (i<j&&v<=arr[j])
        {
            j--;
        }
        arr[i] = arr[j];
        while (i< j&&arr[i]<=v)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = v;
    QuickSort(arr,l,i-1);
    QuickSort(arr,i+1,r);

}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr,0,n-1);
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
/*
描述

给定一个大小为n的数组a和一个整数K，
请找出数组中的第K小元素。

输入


第1行为n

第2行为n个数

第3行为k

 

输出


第k小的数

样例输入

10
9 8 7 6 1 2 3 4 5 10
3

样例输出

3

提示

可以通过改写快速排序算法解决
一趟排序划分出基准位置pivot
1. pivot == k - 1，则pivot 位置数据就是
2. pivot > k - 1，则在左半继续寻找
3. pivot < k - 1，则在右半继续寻找
*/