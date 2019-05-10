/* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrome(char *s, int start, int end){
    if(start >= end){
        return 1;
    }
    if(s[start] != s[end]){
        return 0;
    }
    else{
        return isPalindrome(s, start+1, end-1);
    }
    return 1;
}

char* longestPalindrome(char* s) {
    unsigned short maxLen = strlen(s);
    if(maxLen == 0){
        return "";
    }
    unsigned short start = 0, end = maxLen - 1;
    unsigned short i = 0, j = 0;
    char *str = NULL;
    while(maxLen > 0){
        i = start;
        j = end;
        // printf("maxLen = %u, start = %u, end = %u\n", maxLen, start, end);
        while(s[j] != '\0'){
            if(isPalindrome(s, i, j)){
                str = (char *)malloc(maxLen+1);
                memset(str, '\0', maxLen+1);
                memcpy(str, s+i, maxLen);
                return str;
            }
            ++i;
            ++j;
        }
        start = 0;
        --maxLen;
        end = maxLen - 1;
    }   
    return NULL;
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