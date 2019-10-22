/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE_1 4096 
#define BUF_SIZE_2 10240 

char * countAndSay(int n){
    //
    if(n > 30 || n < 1){
        return (char *)0;
    }
    else if(1 == n)
    {
        return "1";
    }
    int bufSize = n >= 25 ? BUF_SIZE_2 : BUF_SIZE_1;
    char *finalString = (char *)malloc(bufSize);
    char *lastString = (char *)malloc(bufSize);
    memset(finalString, 0, bufSize);
    memset(lastString, 0, bufSize);
    lastString[0] = '1';
    for(int i = 1; i < n; ++i){
        int curNum = lastString[0];
        int count = 1;
        int pos = 0;
        int finalStringLength = 0;
        for(int j = 1; lastString[j] != '\0'; ++j){
            if(curNum == lastString[j]){
                ++count;
            }
            else{
                // printf("pos=%d", pos);
                finalString[pos++] = count + '0';
                finalString[pos++] = curNum;
                finalStringLength += 2;
                if(lastString[j] == '\0'){
                    count = 0;
                    break;
                }
                curNum = lastString[j];
                count = 1;
            }
        }
        if(0 != count){
            finalString[pos++] = count + '0';
            finalString[pos] = curNum;
            finalStringLength += 2;
        }
        memcpy(lastString, finalString, finalStringLength);
        memset(lastString + finalStringLength, 0, bufSize - finalStringLength);
        printf("finalString=%s\n", finalString);
    }
    return finalString;
}

int main(int argc, const char *argv[]){
    countAndSay(1);
    // countAndSay(30);
    return 0;
}