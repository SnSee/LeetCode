/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// num >= 0 && num < 100
// 返回进位
int strAddInt(char *str, int strSize, int pos, int num){
    int deci = num / 10;
    int digit = num % 10;
    int digitSum = str[pos] - '0' + digit;
    str[pos] = digitSum % 10 + '0';
    return deci + digitSum / 10;
}

char *digitalMulBigNum(char *bigNum, int bigNumSize, char digital){
    int tempSumSize = sizeof(char) * 128;
    char *tempSum = (char *)malloc(tempSumSize);
    memset(tempSum, 0, tempSumSize);
    int digitalInt = digital - '0';
    int carry = 0;
    for(int i = bigNumSize; i >= 0; --i){
        int tempResult = digitalInt * (bigNum[i] - '0');
        int pos = tempSumSize - 1 - i;
        carry = strAddInt(tempSum, tempSumSize, pos, tempResult + carry * 10);
    }
}

char * multiply(char * num1, char * num2){
    int sumSize = sizeof(char) * 4096 * 4;
    char *sum = (char *)malloc(sizeof(char) * sumSize);
    memset(sum, 0, sizeof(char) * sumSize);
    int num1Size = strlen(num1);
    int num2Size = strlen(num2);
    for(int i = num1Size; i >= 0; --i){
        for(int j = num2Size; j >= 0; --j){

        }
    }
}

int main(int argc, char *argv[]){
    char bigNum[] = "4444";
    int bigNumSize = sizeof(bigNum) / sizeof(bigNum[0]);
    char num = '4';
    char *ret = digitalMulBigNum(bigNum, bigNumSize, num);
    for(int i = 123; i < 128; ++i){
        printf("%c", ret[i]);
    }
    printf("\nover\n");
    return 0;
}