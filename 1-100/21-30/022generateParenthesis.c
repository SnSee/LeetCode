/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct counts{
    int l;      // 左括号个数
    int r;      // 右括号个数
};
int count = 0;
int tempCount = 100;
char **strs = NULL;
char *generateStr2(int n, char *str1, int *strSize, struct counts *str1Count){
    // 根据已有的字符串生成新的字符串并对当前字符串修改
    // 新字符串(如果有)和修改后的字符串和修改前相比增加了一个字符
    char *str2 = NULL;
    if(str1Count->l > str1Count->r && str1Count->l < n){
        // str1Count->l < n 这个条件是因为如果不满足，str1会生成相同的字符串，即下边str1在else的部分
        str2 = (char *)malloc(sizeof(char) * (2*n+1));
        memset(str2, 0, 2*n+1);
        memcpy(str2, str1, *strSize);
        str2[*strSize] = ')';
    }
    if(str1Count->l < n){
        str1[*strSize] = '(';
        ++(str1Count->l);
    }
    else{
        str1[*strSize] = ')';
        ++(str1Count->r);
    }
    return str2;
}
void fillStrs(int n, char *str1, int strSize, struct counts *str1Count){
    // 根据原始的空字符串和括号个数生成最终的多个字符串
    if(strSize == 2*n){
        return;
    }
    struct counts str2Count = *str1Count;
    char *str2 = generateStr2(n, str1, &strSize, str1Count);
    ++strSize;
    if(str2){
        if(tempCount <= count){
            tempCount += 100;
            strs = (char **)realloc(strs, sizeof(char *) * tempCount);
        }
        strs[count++] = str2;
        ++(str2Count.r);
        fillStrs(n, str2, strSize, &str2Count);
        // printf("in str2 count = %d\n", count);
    }
    // printf("str1 = %s, l = %d, r = %d\n", str1, str1Count->l, str1Count->r);
    // if(str2){
    //     printf("str2 = %s\n", str2);
    // }
    fillStrs(n, str1, strSize, str1Count);
}
char ** generateParenthesis(int n, int* returnSize){
    count = 0;
    tempCount = 100;
    strs = (char **)malloc(sizeof(char *) * tempCount);
    struct counts str1Count = {0, 0};
    char *str = (char *)malloc(sizeof(char) * (2*n+1));
    memset(str, 0, 2*n+1);
    strs[count++] = str;
    fillStrs(n, str, 0, &str1Count);
    *returnSize = count;
    printf("n = %d, count = %d\n", n, count);
    return strs;
}
void printStrs(char **strs, int returnSize){
    for(int i = 0; i < returnSize; ++i){
        printf("%s\n", strs[i]);
    }
}
int main(int argc, char *argv[]){
    int n = 6;
    int returnSize = 0;
    generateParenthesis(n, &returnSize);
    // printf("count = %d\n", count);
    // printStrs(strs, returnSize);
    return 0;
}