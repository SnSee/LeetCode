/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/
#include<stdio.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
double myPow(double x, int n){
    double result = 1.0;
    double tempX = x;
    int multiX = 1;
    if(0 == x){
        return 0.0;
    }
    if(0 == n){
        return 1.0;
    }
    else if(n < 0){
        x = tempX = 1 / x;
        if(MIN_INT == n){
            result *= tempX;
            n = MAX_INT;
        }
        else{
            n = -n;
        }
    }
    while(n > 0){
        if(multiX > n){
            tempX /= x;
            --multiX;
        }
        else{
            result *= tempX;
            n -= multiX;
            tempX *= x;
            ++multiX;
        }
        // printf("tempX = %lf, multiX = %d, n = %d, myPow.result = %lf\n", tempX, multiX, n, result);
    }
    return result;
}

int main(int argc, char *argv[]){
    // double xArray[] = {2.00000, 2.10000, 2.00000, 0.00001};
    // int nArray[] = {10, 3, -2, 2147483647};
    double xArray[] = {34};
    int nArray[] = {-3};
    int size = sizeof(nArray)/sizeof(nArray[0]);
    for(int i = 0; i < size; ++i){
        printf("x = %lf, n = %d, result = %lf\n", xArray[i], nArray[i], myPow(xArray[i], nArray[i]));
    }
    // printf("test\n");
    return 0;
}