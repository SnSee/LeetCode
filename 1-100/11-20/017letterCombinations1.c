/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get79Count(char *digits){
    int count79 = 0;
    int i = 0;
    while(digits[i] != '\0'){
        if(digits[i] == '7' || digits[i] == '9'){
            ++count79;
        }
        ++i;
    }
    return count79;
}
char map[][4] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void setRet(char **start, int size, char *digits, int len){
    int leNear = size;
    int parts = 1;
    for(int i = 0; i < len; ++i){
        int letters = 3;
        if(digits[i] == '7' || digits[i] == '9'){
            letters = 4;
        }
        leNear /= letters;  // 相邻且相同的字符的个数
        for(int z = 0; z < parts; ++z){
            for(int j = 0; j < letters; ++j){
                for(int k = 0; k < leNear; ++k){
                    start[z*size/parts+j*leNear+k][i] = map[digits[i] - '0'][j];
                }
            }
        }
        parts *= letters;
    }
}
char ** letterCombinations(char * digits, int* returnSize){
    int digitsSize = strlen(digits);
    if(!digitsSize){
        *returnSize = 0;
        return NULL;
    }
    int letterCount = 0;
    int count79 = get79Count(digits);
    *returnSize = 1;
    for(int i = 0; i < count79; ++i){
        *returnSize *= 4;
    } 
    for(int i = 0; i < digitsSize - count79; ++i){
        *returnSize *= 3;
    }
    char **ret = (char **)malloc(*returnSize * sizeof(char *));
    for(int i = 0; i < *returnSize; ++i){
        ret[i] = (char *)malloc(digitsSize+1);
        ret[i][digitsSize] = '\0'; 
    }
    setRet(ret, *returnSize, digits, digitsSize);
    return ret;
}

int main(int argc, char *argv[]){

    char digits[] = "2";
    int returnSize = 0;
    char **ret = letterCombinations(digits, &returnSize);
    printf("[");
    for(int i = 0; i < returnSize; ++i){
        i == 0 ? 0 : putchar(' ');
        printf("\"%s\"", ret[i]);
        i == returnSize - 1 ? 0 : putchar(',');
    }
    printf("].\n");
    return 0;
}