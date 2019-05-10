/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int len, int strsSize) {
    char *ret = (char *)malloc(1024);
    memset(ret, 0, 1024);
    char *strss = (char *)strs;
    int i = 0, j = 0;
    while(1){
        j = 0;
        while(j < strsSize - 1){
            if(strss[j*len + i] == '\0'){
                return ret;
            }
            ++j;
            if(strss[j*len + i] != strss[(j-1)*len + i]){
                return ret;
            }
        }
        ret[i] = strss[j*len + i];
        ++i;
    }
}

int main(int argc, char *argv[]){

    char str[][10] = {"flower", "flow", "flight"};
    char *ret = longestCommonPrefix((char **)str, 10, 3);
    printf("ret = %s\n", ret);
    return 0;
}
