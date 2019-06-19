/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_INT2 1073741824
int divide(int dividend, int divisor){
    if(0 == divisor){
        return 0;
    }
    int consult = 0;
    int positive = 1;   // 标记正负
    int _divisor[32] = {0};
    int multiple[32] = {1};
    int i = 0;
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
        positive = 0;
    }
    if(divisor == 1){
        return dividend;
    }
    if(MIN_INT == dividend){
        if(divisor == -1){
            return MAX_INT;
        }
        if(divisor == MIN_INT){
            return 1;
        }
        dividend = divisor > 0 ? dividend + divisor : dividend - divisor;
        consult += 1;
    }
    if(dividend < 0){
        dividend = -dividend;
    }
    if(MIN_INT == divisor){
        if(MIN_INT == dividend){
            return 1;
        }
        return 0;
    }
    if(divisor < 0){
        divisor = -divisor;
    }
    _divisor[0] = divisor;
    while(dividend >= divisor){
        if(dividend >= _divisor[i]){
            dividend -= _divisor[i];
            consult += multiple[i];
            if(_divisor[i] < MAX_INT2){
                _divisor[i+1] = _divisor[i] + _divisor[i];
                multiple[i+1] = multiple[i] + multiple[i];
                ++i;
            }
        }
        else{
            --i;
        }
    }
    return positive ? consult : -consult;
}
int main(int argc, const char *argv[]){
    int dividend = 2147483647;
    int divisor = 2;
    int consult = divide(dividend, divisor);
    printf("consult = %d\n", consult);
    return 0;
}