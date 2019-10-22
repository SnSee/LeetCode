/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121 输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

// 方法一：转换为字符串

#include <stdio.h>
#include <stdlib.h>

typedef enum Bool{ 
    false, true
}bool;

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    char *num = (char *)malloc(20);
    char *p = num, *q = num;
    while(x != 0){
        *p++ = x % 10 + '0';
        x /= 10;
    }
    *p-- = '\0';
    while(p >= q){
        if(*p-- != *q++){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){

    int num = 12321;
    bool ret = isPalindrome(num);
    if(ret)
        printf("%d is palindrome\n", num);
    else
        printf("%d is not palindrome\n", num);
    
    return 0;
}