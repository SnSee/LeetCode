/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
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
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    if(numsSize < 4){
        *returnSize = 0;
        return NULL;
    }
    int h, i, j, k;
    sort(nums, nums + numsSize - 1);
    // 申请临时空间，如果不够大，后面进行扩展
    int tempCount = 100;
    int **planarArray = (int **)malloc(sizeof(int *) * tempCount);
    for(h = 0; h < numsSize - 3; ++h){
        if(h > 0 && nums[h] == nums[h-1]){
            continue;
        }
        if(nums[h] * 4 >= target){
            if(nums[h] != nums[h+1] || nums[h] != nums[h+2] || nums[h] != nums[h+3])
                break;
        }
        for(i = h + 1; i < numsSize - 2; ++i){
            if(i > h + 1 && nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] * 3 >= target - nums[h]){
                if(nums[i] != nums[i+1] || nums[i] != nums[i+2])
                    break;
            }
            for(j = i + 1; j < numsSize - 1; ++j){
                if(j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                if(nums[j] * 2 >= target - nums[h] - nums[i]){
                    if(nums[j] != nums[j+1])
                        break;
                }
                for(k = j + 1; k < numsSize; ++k){
                    if(k > j + 1 && nums[k] == nums[k-1]){
                        continue;
                    }
                    if(nums[k] > target - nums[h] - nums[i] - nums[j]){
                        break;
                    }
                    if(nums[k] == target - nums[h] - nums[i] - nums[j]){
                        *returnSize += 1;
                        if(*returnSize > tempCount){
                            tempCount += 100;
                            planarArray = (int **)realloc(planarArray, sizeof(int *)*tempCount);
                        }
                        int *oArray = (int *)malloc(sizeof(int) * 4);
                        oArray[0] = nums[h];
                        oArray[1] = nums[i];
                        oArray[2] = nums[j];
                        oArray[3] = nums[k];
                        planarArray[*returnSize-1] = oArray;
                    }
                }
            }
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i){
        (*returnColumnSizes)[i] = 4;
    }
    return planarArray;
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
int main(int argc, char *argv[]){
    int nums[] = {-2, -1, 0, 0, 1, 2};
    int target = 0;
    // int nums[] = {0, 0, 0, 0};
    // int target = 1;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int returnSize = 0;
    int *returnColumnSize;
    int **planarArray = fourSum(nums, numsSize, target, &returnSize, &returnColumnSize);
    printf("returnSize = %d\n", returnSize);
    print2Array(planarArray, returnSize, 4);
    return 0;
}