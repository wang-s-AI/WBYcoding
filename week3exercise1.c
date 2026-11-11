#include <stdio.h>
#include <windows.h>
int mul2(int num);
int mul3(int num);

int main(void)
{
    SetConsoleOutputCP(65001);
    int n;
    printf("请输入一个整数：");
    scanf("%d", &n);
    int is_odd = (mul2(n) == 0);
    int not_mult3 = (mul3(n) == 0);
    int not_mult6 = !(mul2(n) && mul3(n));

    if(is_odd && not_mult3 && not_mult6){
        printf("该数是奇数，且不是3的倍数，也不是6的倍数\n");
        printf("this number is odd and not a multiple of 3 or 6\n");
    }
    else{
        printf("该数不满足条件\n");
        printf("this number does not meet the criteria\n");
        printf("is_odd: %d, not_mult3: %d, not_mult6: %d\n", is_odd, not_mult3, not_mult6);
    }
    return 0;
}

int mul2(int num){
    return num % 2 == 0;
}
int mul3(int num){
    return num % 3 == 0;
}