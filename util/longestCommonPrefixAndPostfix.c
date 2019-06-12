/*
 * 寻找字符串不同子串的最长的相同的前缀和后缀，并输出其长度
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *findLongest(char *str, int size){
    if(size <= 0){
        return NULL;
    }
    int *next = (int *)malloc(sizeof(int) * size);
    /*
     * 如果没有相同前缀后缀，值为-1，有一个则值为0，类推
    */
    next[0] = -1;
    for(int i = 1; i < size; ++i){
        int j = next[i-1];
        /* 1. j = -1 时跳出循环，有str[j+1] == str[i]时跳出循环
         * 2. 进入循环说明上一个子字符串的最长前缀的下一个字符与本次子字符串后缀最后一个字符相同
         * 3. 由于j的值都是从next数组中取的，所以当出现j = -1的情况时，
         *    说明不能存在更长的相同前后缀了，此时j的值就是不考虑i位置的最长相同前后缀长度tempMax，
         *    后续判断 str[i] 和 str[j+1] 是否相等，不相等表明不存在，next[i] = -1
         *    相等说明存在且长度为 tempMax + 1
        */
        while((str[j+1] != str[i]) && j >= 0){
            /* 进入循环说明可能存在相同前后缀
             * 进入循环
            */
            j = next[j];
        }

        /*
         * 
        */
        if(str[j+1] == str[i]){
            next[i] = j + 1;
        }
        else{ // j = -1 跳出的循环
            next[i] = -1;
        }
    }

    return next;
}
int main(int argc, const char *argv[]){
    return 0;
}