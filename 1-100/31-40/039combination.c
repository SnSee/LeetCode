/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。
说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
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

int _target = 0;
int *columnSize;
int** combination;
int combCount = 0;
int combinationSize = 100;
int diffZero(int *candidates, int candidatesSize, int *nums, int numsSize, int validSize, int tempSum){
    for(int i = 0; i < candidatesSize; ++i){
        if(tempSum == _target){
            // 符合的
            if(combinationSize <= combCount + 1){
                // 扩容
                combinationSize *= 2;
                int **newCombination = (int **)malloc(sizeof(int *) * combinationSize);
                memcpy((int*)newCombination, (int*)combination, sizeof(int*)*combinationSize/2);
                free(combination);
                combination = newCombination;
                int *newColumnSize = (int *)malloc(sizeof(int) * combinationSize);
                memcpy(newColumnSize, columnSize, sizeof(int)*combinationSize/2);
                free(columnSize);
                columnSize = newColumnSize;
            }
            combination[combCount] = nums;
            columnSize[combCount] = validSize;
            ++combCount;
            return 0;
        }
        else if(tempSum > _target){
            // 不符合的
            continue;
        }
        else{
            // 可能符合的
            if(validSize > 0 && nums[validSize - 1] > candidates[i]){
                // 去重
                continue;
            }
            int newNumsSize = numsSize;
            if(validSize >= numsSize){
                newNumsSize *= 2;
            }
            int *newNums = (int *)malloc(sizeof(int) * newNumsSize);
            int newValidSize = validSize;
            memcpy(newNums, nums, numsSize * sizeof(int));
            newNums[newValidSize++] = candidates[i];
            diffZero(candidates, candidatesSize, newNums, newNumsSize, newValidSize, tempSum + candidates[i]);
        }
    }
    free(nums);
    return 0;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    _target = target;
    combCount = 0;
    combination = (int **)malloc(sizeof(int *) * combinationSize);
    columnSize = (int *)malloc(sizeof(int) * combinationSize);
    int *nums = (int *)malloc(sizeof(int) * 100);
    memset(nums, 0, 100 * sizeof(int));
    diffZero(candidates, candidatesSize, nums, 100, 0, 0);
    *returnSize = combCount;
    *returnColumnSizes = columnSize;
    return combination;
}

int main(int argc, const char *argv[]){

    int candidates[] = {8,10,6,3,4,12,11,5,9};
    int target = 28;
    int returnSize;
    int *returnColumnSizes;
    int **combination = combinationSum((int *)candidates, sizeof(candidates)/sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);
    printf("returnSize=%d\n", returnSize);
    for(int i = 0; i < returnSize; ++i){
        printf("size[%d]=%d\n", i, returnColumnSizes[i]);
    }
    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < returnColumnSizes[i]; ++j){
            printf("%d, ", combination[i][j]);
        }
        printf("\n");
    }
    return 0;
}