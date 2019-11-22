/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
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

// 返回当前nums数字总和
// int NumsSumTarget(int *candidates, int candidatesSize, int target, int *nums, int numsSize, int validSize, int tempSum, int index){
//     if(index >= candidatesSize){
//         return tempSum;
//     }
//     tempSum += candidates[index];
//     nums[validSize] += candidates[index];
//     ++validSize;
//     if (tempSum < target)
//     {
//         return NumsSumTarget(candidates, candidatesSize, target, nums, numsSize, validSize, tempSum, index + 1);
//     }
//     return tempSum;
// }

// int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
// {
//     int numsSize = 1000;
//     int validSize = 0;
//     int *nums = (int *)malloc(sizeof(int) * numsSize);
//     int **result = (int **)malloc(sizeof(int) * 1000);
//     int count = 0;
//     sort(candidates, candidates + candidatesSize - 1);
//     *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
//     for(int i = 0; i < candidatesSize; ++i){
//         validSize = 0;
//         int tempSum = NumsSumTarget(candidates, candidatesSize, target, nums, numsSize, validSize, 0, i);
//         if(tempSum == target){
//             result[count] = (int *)malloc(sizeof(int) * 1000);
//             memcpy(result[count], nums, validSize);
//             (*returnColumnSizes)[count] = validSize;
//             ++count;
//         }
//     }
//     *returnSize = count;
// }

int main(int argc, const char *argv[]){
    // int candidates[] = {10,1,2,7,6,1,5};
    // int target = 8;
    // int returnSize;
    // int *returnColumnSizes;
    // int **combination = combinationSum((int *)candidates, sizeof(candidates)/sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);
    // printf("returnSize=%d\n", returnSize);
    // for(int i = 0; i < returnSize; ++i){
    //     for(int j = 0; j < returnColumnSizes[i]; ++j){
    //         printf("%d, ", combination[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}