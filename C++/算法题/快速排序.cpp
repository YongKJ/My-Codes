#include <stdio.h>
#include <stdlib.h>

int quick_select(int a[], int l, int r, int k) {
	int p = rand() % (r - l + 1) + l;
	int x = a[p];
	{int t = a[p]; a[p] = a[r]; a[r] = t;}
	int i = l, j = r;
	while(i < j) {
		while(i < j && a[i] < x) i++;
		if(i < j) {
			a[j] = a[i];
			j--;
		}
		while(i < j && a[j] > x) j--;
		if(i < j) {
			a[i] = a[j];
			i++;
		}
	}
	a[i] = x;
	p = i;
	if(i - l + 1 == k) return a[i];
	if(i - l + 1 < k) return quick_select(a,i+1,r,k-(i-l+1)); //填空
	else return quick_select(a, l, i - 1, k);
}
	
int main()
{
	int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
	printf("%d\n", quick_select(a, 0, 14, 5));
	return 0;
}

/*
#include <stdio.h>
 
int quick_select(int a[], int l, int r, int k) {
    int p = rand() % (r - l + 1) + l;
    int x = a[p];     //随机产生一个范围是【l，r】的p，并将a【p】的值赋给X 
    {int t = a[p]; a[p] = a[r]; a[r] = t;}   //这里将a【p】与最后一个数交换，它为什么要这样做请看接下来的代码
    int i = l, j = r;   //首先把l和r赋值给i和j
    while(i < j) {   //程序用a【i】和a【j】分别从数组的两端向中间移动，每次的移动都会将比X小的数放在角标为i的地方，比X大的放在角标为j的地方
        while(i < j && a[i] < x) i++;  //首先是从头开始往后移动，找出比X大的数（这个数要放在后面）
        if(i < j) {    // 先进行第一次的分析，后面的循环分析是一样的
            a[j] = a[i];   // 在进行第一次将前面比X大的数换到j的位置时，不用担心数组中最后一个元素被替换，因为X已经保存了这个元素
            j--;           //（而在后面几次这里的循环中你会发现这个值被替换前，这个值已经放到其它位置上了，所以不用担心有元素值没了）
        }    //在这一步我们也会发现最后面的元素已经被i所在的元素赋值了，而当前的i还存着应该放在后面的值，所以后面会把这个值替换
        while(i < j && a[j] > x) j--;  //从尾部往前走，找出比X大的值 放在i的位置，通过上面的步骤，你会发现那个i的值已经存放在别的地方
        if(i < j) {                    //而我们也通过i保存比X小的数才是正常的，所以把后面的数赋值给a【i】
            a[i] = a[j];                //然后进行同样的操作是一样的意思
            i++;      // 举个例子如49,38,27,13,65,76,97  如果p=2，X=27，那么将其换到最后面时就成了49,38,97,13,65,76,27, i=0,j=6
        }             //第一次操作从头比较时,当i=0时就数组就换成了49，38，97，13，65，76，49（x保存了27，所以不用担心！），然后j=5；
    }                 //从后开始比较时，j=3时，13<27，所以放在i的地方，即取代49，变成13，38，97，13，65，76，49（后面是一样的）
    a[i] = x;   //通过上面的循环操作，就会发现最后i=j，同时i左边的数都比X小，i右边的数都比X大，最后把缺少的数（也就是X）放上去
    p = i;
    if(i - l + 1 == k) return a[i];  //如果满足条件，就说明这就是要找的数所以直接返回这个值
    if(i - l + 1 < k) return quick_select( _______a,i+1,r,k-(i-l+1)______________________ ); //填空
    else return quick_select(a, l, i - 1, k);  //通过分析i-l+1 和k 的大小来进行选择操作，。如果因为此时i的值大小就是这个值在排序后的位置
}                                              //选择操作：如果i-l+1比k大，那就说明k所代表的值在左边，否则就在右边，然后再进行重复的递归操作
 
int main()
{
    int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
    printf("%d\n", quick_select(a, 0, 14, 5));
    return 0;
}
*/
/*
以下代码可以从数组a[]中找出第k小的元素。


它使用了类似快速排序中的分治算法，期望时间复杂度是O(N)的。


请仔细阅读分析源码，填写划线部分缺失的内容。

#include <stdio.h>

int quick_select(int a[], int l, int r, int k) {
	int p = rand() % (r - l + 1) + l;
	int x = a[p];
	{int t = a[p]; a[p] = a[r]; a[r] = t;}
	int i = l, j = r;
	while(i < j) {
		while(i < j && a[i] < x) i++;
		if(i < j) {
			a[j] = a[i];
			j--;
		}
		while(i < j && a[j] > x) j--;
		if(i < j) {
			a[i] = a[j];
			i++;
		}
	}
	a[i] = x;
	p = i;
	if(i - l + 1 == k) return a[i];
	if(i - l + 1 < k) return quick_select( _____________________________ ); //填空
	else return quick_select(a, l, i - 1, k);
}
	
int main()
{
	int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};
	printf("%d\n", quick_select(a, 0, 14, 5));
	return 0;
}


注意：只填写划线部分缺少的代码，不要抄写已经存在的代码或符号。

*/