/* HDU1201 18岁生日 */
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 18;
const int YEARDAYS = 365;
// 闰年计算函数
int leapyear(int year) {
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return 1;
    return 0;
}
int main()
{
    int t, byear, bmonth, bday, sum;
    scanf("%d", &t);
    while(t--) {
        scanf("%d-%d-%d", &byear, &bmonth, &bday);
        if(bmonth == 2 && bday == 29 && leapyear(byear + N) != 1)
            printf("-1\n");
        else {
            // 计算天数
            sum = 0;
            sum = YEARDAYS * N;             // 每年365天，18年总天数
            for(int i=1; i<N; i++)              // 出生年和18岁那年以外的闰年天数
                sum +=  leapyear(byear + i);
            if(bmonth > 2)
                sum += leapyear(byear + N); // 18岁那年的闰年天数
            else if(bmonth < 2 || bday != 29)
                sum += leapyear(byear);     // 出生年的闰年天数
            printf("%d\n", sum);
        }
    }
    return 0;
}