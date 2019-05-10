/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 2147483647
void printArray(int *nums, int size){
    for(int i = 0; i < size; ++i){
        printf("%d ", nums[i]);
    }
    printf("\n");
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
int threeSumClosest(int* nums, int numsSize, int target){
    int flag, tempSub;
    int finalSub = 2147483647, finalFlag;
    int j, k;
    sort(nums, nums + numsSize - 1);
    for(int i = 0; i < numsSize - 2; ++i){
        j = i + 1;
        k = numsSize - 1;
        while(j < k){
            tempSub = nums[i] + nums[j] + nums[k] - target;
            if(0 == tempSub){
                return target;
            }
            flag = (tempSub > 0 ? 1 : -1);
            if(finalSub > tempSub*flag){
                finalSub = tempSub * flag;
                finalFlag = flag;
            }
            flag > 0 ? --k : ++j;
        } 
    }    
    printf("finalSub = %d, finalFlag = %d\n", finalSub, finalFlag);
    return target + finalSub * finalFlag;
}

int main(int argc, char *argv[]){
    int nums[] = {-1,0,1,1,55};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 3;
    int sum = threeSumClosest(nums, numsSize, target);
    printf("sum = %d\n", sum);
    return 0;
}