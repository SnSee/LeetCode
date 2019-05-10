/* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 中心展开法
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    int maxLen = 0;
    int start = 0;
    int i, j, k;
    char *str = NULL;
    for(i = 0; i < n; ++i){
        for(j = i, k = i; j >= 0 && k <= n - 1; --j, ++k){
            if(s[j] == s[k]){
                if(maxLen < k - j + 1){
                    maxLen = k - j + 1;
                    start = j;
                }
            }
            else{
                break;
            }
        }
        for(j = i, k = i + 1; j >= 0 && k <= n - 1; --j, ++k){
            if(s[j] == s[k]){
                if(maxLen < k - j + 1){
                    maxLen = k - j + 1;
                    start = j;
                }
            }
            else
                break;
        }
    }
    str = (char *)malloc(maxLen + 1);
    memcpy(str, s+start, maxLen);
    str[maxLen] = '\0';
    return str;
}

int main(int argc, char *argv[]){

    char s[1024] = "";
    while(1){
        printf("输入字符串：");
        scanf("%s", s);
        //printf("sizeof(s) = %lu\n", sizeof(s));
        char *str = longestPalindrome(s);
        printf("str = %s\n", str);
    }
    return 0;
}