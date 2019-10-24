/*
排序 + 回溯算法 + 剪枝算法
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _target = 0;
int *columnSize;
int** combination;
int combCount = 0;
int combinationSize;
int *_candidates;
int _candidatesSize;

// 快速排序递归版(从小到大)
void sort(int *left, int *right){
    if(left >= right){
        return;
    }
    // 基准值
    int *start = left, *end = right;
    int pivot = *(left + (right - left)/2);
    // 使pivot的值和最左侧的值交换位置
    *(left + (right - left)/2) = *left;
    *left = pivot;
    while(start < end){
        while(start < end && pivot <= *end){
            --end;
        }
        *start = *end;      // 此时end位置的数本来应该是pivot，但pivot已被维护，所以该位置的数无关紧要
                            // 但要在循环结束时用pivot替换start和end重合位置的数
        while(start < end && pivot >= *start){
            ++start;
        }
        *end = *start;      // 同上
    }
    *start = pivot; // 此时start和end应该是同一个位置
    sort(left, start - 1);
    sort(start + 1, right);
}

int sumCompareToTarget(int* candidates, int candidatesSize, int *nums, int numsSize, int validSize, int tempSum, int index){
    if(tempSum > _target){
        return -1;
    }
    else if(tempSum < _target){
        for(int i = index; i < candidatesSize; ++i){
            nums[validSize] = candidates[i];
            int ret = sumCompareToTarget(candidates, candidatesSize, nums, numsSize, validSize + 1, tempSum + candidates[i], i);
            if(-1 == ret){
                // 剪枝
                return 0;
            }
        }
    }
    else{
        // 
        combination[combCount] = (int *)malloc(sizeof(int) * validSize);
        memcpy(combination[combCount], nums, sizeof(int) * validSize);
        columnSize[combCount] = validSize;
        ++combCount;
    } 
    return 0;
}

void initVars(int *candidates, int candidatesSize, int target){
    _target = target;
    combinationSize = 1000;
    combination = (int **)malloc(sizeof(int*) * combinationSize);
    combCount = 0;
    columnSize = (int *)malloc(sizeof(int) * 1000);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    initVars(candidates, candidatesSize, target);    
    // 排序
    sort(candidates, candidates + candidatesSize - 1);
    int numsSize = 1000;
    int validSize = 0;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    memset(nums, 0, sizeof(int)*numsSize);
    sumCompareToTarget(candidates, candidatesSize, nums, numsSize, validSize, nums[0], 0);
    printf("combCount=%d\n", combCount);
    *returnSize = combCount;
    *returnColumnSizes = columnSize;
    return combination;
}


int main(int argc, const char *argv[]){
    int candidates[] = {4,2,7,5,6};
    int target = 16;
    // int candidates[] = {2,3,6,7};
    // int target = 7;
    int returnSize;
    int *returnColumnSizes;
    int **combination = combinationSum((int *)candidates, sizeof(candidates)/sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < returnColumnSizes[i]; ++j){
            printf("%d, ", combination[i][j]);
        }
        printf("\n");
    }
    return 0;
}