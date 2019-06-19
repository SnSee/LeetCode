/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

*/


// 暴力法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strStr(char * haystack, char * needle){
    if(NULL == needle || needle[0] == 0){
        return 0;
    }
    if(NULL == haystack){
        return -1;
    }
    int hlen = strlen(haystack);
    int plen = strlen(needle);
    int j = 0;
    if(hlen < plen){
        return -1;
    }
    for(int i = 0; i <= hlen - plen; ++i){
        for(j = 0; j < plen; ++j){
            if(haystack[i+j] != needle[j]){
                break;
            }
        }
        if(j == plen){
            return i;
        }
    } 
    return -1;
}
int main(int argc, const char *argv[]){
    char haystack[] = "aacbddafasdfacbdc";
    char needle[] = "acbdc";
    // char haystack[] = "";
    // char needle[] = "";
    int pos = strStr(haystack, needle);
    printf("pos = %d\n", pos);
    return 0;
}