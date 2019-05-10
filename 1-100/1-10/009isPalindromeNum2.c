/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

// 方法二：不转换为字符串

#include <stdio.h>
#include <stdlib.h>

typedef enum Bool{
    false, true
}bool;

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    long y = x, z = 0;
    while(y != 0){
        z = z*10 + y%10;
        y /= 10;
    }
    return x == z ? true : false;
}

int main(int argc, char *argv[]){

    int num = 12345;
    bool ret = isPalindrome(num);
    if(ret)
        printf("%d is palindrome\n", num);
    else
        printf("%d is not palindrome\n", num);
    
    return 0;
}