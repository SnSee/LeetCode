/* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 动态规划法
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestPalindrome(char* s) {
    unsigned short n = strlen(s);
    if(n == 0){
        return "";
    }
    unsigned short start = 0;
    unsigned short i = 0, j = 0;
    unsigned short maxLen = 1;
    char *str = NULL;
    char dp[n][n];
    
    for(i=0; i < n; ++i){
        for(j=0; j <= i; ++j){
            if(i - j < 2){
                // 相邻两字母是否相同，同一个位置字母必定相同（如dp[1][1]）
                dp[j][i] = (s[i] == s[j] ? 1 : 0);
            }
            else{
                // 当前位置字母相同并且中间的子串是回文
                dp[j][i] = ((s[i]==s[j] && dp[j+1][i-1]) ? 1 : 0);
            }

            if(dp[j][i] && maxLen < i - j + 1){
                maxLen = i - j + 1;
                start = j;
            }
        }
    }
    str = (char *)malloc(maxLen + 1);
    memset(str, 0, maxLen + 1);
    memcpy(str, s+start, maxLen);
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
    int n = 5;
    // char **dp = (char **)malloc(n);
    // for(int k = 0; k < n; ++k){
    //     dp[k] = (char *)malloc(n);
    //     memset(dp[k], 0, n);
    //     for(int j = 0; j < n; ++j){
    //         printf("dp[%d][%d] = %d, ", k, j, dp[k][j]);
    //     }
    //     printf("\n");
    // }
    // printf("================\n");
    // for(int i = 0; i < 5; ++i){
    //     for(int j = 0; j < 5; ++j){
    //         printf("dp[%d][%d] = %d, ", i, j, dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}