/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int numInArr(int *arr, int arrSize, int num){
    for(int i = 0; i < arrSize; ++i){
        if(num == arr[i]){
            return 1;
        }
    }
    return 0;
}

void reverse(int *nums, int numsSize, int *arr, int arrCount, int **ret, int *returnSize){
    if(arrCount == numsSize){
        ret[*returnSize] = arr;
        ++(*returnSize);
        // 回溯
        return;
    }
    int arrUsed = 0;
    for(int i = 0; i < numsSize; ++i){
        if(!numInArr(arr, arrCount, nums[i])){
            int *tempArr;
            if(arrUsed){
                tempArr = (int *)malloc(sizeof(int) * numsSize);
                memcpy(tempArr, arr, sizeof(int) * arrCount);
            }
            else{
                tempArr = arr;
                arrUsed = 1;
            }
            tempArr[arrCount] = nums[i];
            reverse(nums, numsSize, tempArr, arrCount + 1, ret, returnSize);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int retSize = 1;
    for(int i = 1; i <= numsSize; ++i){
        retSize *= i;
    }
    int **ret = (int**)malloc(sizeof(int*) * retSize);
    int *arr = (int *)malloc(sizeof(int) * numsSize); 
    *returnSize = 0;
    reverse(nums, numsSize, arr, 0, ret, returnSize); 
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i){
        (*returnColumnSizes)[i] = numsSize;
    }
    return ret;
}

int main(int argc, char *argv[]){
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize = 0;
    int *returnColumnSizes;
    int **ret = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    printf("return\n");
    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < numsSize; ++j){
            printf("%d, ", ret[i][j]);
        }
        printf("\n");
    }
    printf("over\n");
    return 0;
}