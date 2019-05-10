/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array. 长度不都是 3 ？？？
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//打印一维数组
void printArray1(int *nums, int numsSize){
    printf("[");
    for(int i = 0; i < numsSize; ++i){
        printf("%d, ", nums[i]);
    }
    printf("]\n");
}
// 打印二维数组
void print2Array(int **sums, int size, int coSize){
    for(int i = 0; i < size; ++i){
        printf("[");
        for(int j = 0; j < coSize; ++j){
            printf("%d, ", sums[i][j]);
        }
        printf("]\n");
    }
}

// 快速排序(从小到大)
void sort(int *left, int *right){
    if(left >= right){
        return;
    }
    // 基准值
    int *start = left, *end = right;
    int pivot = *(left + (right - left)/2);
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
int inList(int **nums, int size, int *num){
    if(size <= 0){
        return 0;
    }
    for(int i = 0; i < size; ++i){
        if(nums[i][0] == num[0] && nums[i][1] == num[1] && nums[i][2] == num[2]){
            return 1;
        }
    }
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize <= 2){
        *returnSize = 0;
        return (int **)NULL;
    }
    sort(nums, nums + numsSize - 1); 
    int sumCount = numsSize;
    // sumCount = 10000;
    int SUM_COUNT = sumCount;
    int **sum = (int **)malloc(sumCount * sizeof(int *));
    *returnSize = 0;
    int zeroPos;
    // 找到0或第一个正数的位置
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] >= 0){
            zeroPos = i;
            break;
        }
    }
    int count = 0;
    int t = 0;
    // 循环查找
    for(int i = 0; i <= zeroPos; ++i){
        for(int j = i + 1; j < numsSize; ++j){
            for(int k = zeroPos; k < numsSize; ++k){
                if(k <= j){
                    continue;
                }
                if(nums[k] + nums[i] + nums[j] == 0){
                   if(count >= sumCount - 1){
                       sumCount += SUM_COUNT;
                       sum = (int **)realloc((int *)sum, sizeof(int *) * sumCount);
                    }
                    sum[count] = (int *)malloc(sizeof(int) * 3);
                    sum[count][0] = nums[i];
                    sum[count][1] = nums[j];
                    sum[count][2] = nums[k];
                    ++count;
                    break;
                }
            }
        }
    }
    // 如果没有满足条件的三个数
    if(count == 0){
        *returnSize = 0;
        return (int **)NULL;
    }
    // 去重
    int **retSum = (int **)malloc(count * sizeof(int *));
    int retCount = 0;
    int j = 0;
    for(int i = 0; i < count; ++i){
        if(!inList(retSum, retCount, sum[i])){
            retSum[retCount++] = sum[i];
        }
    }
    // 释放内存
    free(sum);
    *returnColumnSizes = (int *)malloc(sizeof(int) * retCount);
    for(int i = 0; i < retCount; ++i){
        (*returnColumnSizes)[i] = 3;
    }
    *returnSize = retCount;
    return retSum;
}
int main(int argc, char *argv[]){
    // int nums[] = {-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
    // int nums[] = {-1,0,1,2,-1,-4};
    int nums[] = {0, 0, 0};
    int returnSize;
    int *returnColumnSizes;
    int **ret = threeSum(nums, sizeof(nums)/sizeof(nums[0]), &returnSize, &returnColumnSizes);
    if(NULL == ret){
        printf("没有找到\n");
    }
    else{
        printf("result is:\n");
        for(int i = 0; i < returnSize; ++i){
            printf("[%d, %d, %d]\n", ret[i][0], ret[i][1], ret[i][2]);
        }
    }
    return 0;
}