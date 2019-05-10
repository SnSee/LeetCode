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
    int sub, sum, flag;
    int finalSub = 2147483647, finalFlag;
    int j, k;
    sort(nums, nums + numsSize - 1);
    for(int i = 0; i < numsSize - 2; ++i){
        j = i + 1;
        k = numsSize - 1;
        sum = nums[i] + nums[j] + nums[k];
        if(sum < target){
            flag = -1;
            while(j < k){
                // printf("[%d, %d, %d]\n", nums[i], nums[j], nums[k]);
                sum = nums[i] + nums[j] + nums[k];
                if(sum < target){
                    sub = target - sum;
                    ++j;
                }
                else if(sum > target){
                    if(-sub > sum - target){
                        sub = sum - target;
                        flag = 1;
                    }
                    if(finalSub > sub * flag){
                        finalSub = sub;
                        finalFlag = flag;
                    }
                    // printf("finalSub = %d, sub = %d, flag = %d\n", finalSub, sub, flag);
                    --k;
                    j = i + 1;
                }
                else{
                    return target;
                }
            }
        }
        else if(sum > target){
            flag = 1;
            while(j < k){
                // printf("[%d, %d, %d]\n", nums[i], nums[j], nums[k]);
                sum = nums[i] + nums[j] + nums[k];
                if(sum > target){
                    sub = sum - target;
                    --k;
                }
                else if(sum < target){
                    if(sub > target - sum){
                        sub = target - sum;
                        flag = -1;
                    }
                    if(finalSub > sub * flag){
                        finalSub = sub;
                        finalFlag = flag;
                    }
                    // printf("finalSub = %d, sub = %d, flag = %d\n", finalSub, sub, flag);
                    ++j;
                    k = numsSize - 1;
                }
                else{
                    return target;
                }
            }
        }
        else{
            return target;
        }
        if(finalSub > sub){
            finalSub = sub;
            finalFlag = flag;
        }
    }    
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