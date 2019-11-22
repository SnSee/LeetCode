/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/*
 * 例子：对于 1,2,3,4，最大排序是 4,3,2,1，接着是 4,3,1,2-> 4,2,3,1 -> 4,2,1,3 -> 4,1,3,2 -> 4,1,2,3
 * 3,4,2,1 -> 3,4,1,2 -> 3,2,4,1 -> 3,2,1,4 -> 3,1,4,2 -> 3,1,2,4
 * ...
 * 最小排序是 1,2,3,4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArr(int *nums, int numsSize){
    for(int i = 0; i < numsSize; ++i){
        printf("%d, ", nums[i]);
    }
    printf("\n");
}
void reverseArray(int *firstNum, int *lastNum){
    int *pL = firstNum;
    int *pR = lastNum;
    while(pL < pR){
        *pL = *pL ^ *pR;
        *pR = *pL ^ *pR;
        *pL = *pL ^ *pR;
        ++pL;
        --pR;
    }
}
void nextPermutation(int* nums, int numsSize){
    int biggest = 1;        // 是否已经是降序
    int changePos = 0;
    for(int i = numsSize - 1; i > 0; --i){
        if(nums[i - 1] < nums[i]){
            changePos = i - 1;
            biggest = 0;
            break;
        }
    }
    if(biggest){
        // 倒叙
        reverseArray(nums, nums + numsSize - 1);
    }
    else{
        // 从最后一位往前查找，找到比changePos位置的数大的数并交换
        for(int i = numsSize - 1; i > changePos; --i){
            if(nums[i] > nums[changePos]){
                nums[changePos] = nums[changePos] ^ nums[i];
                nums[i] = nums[changePos] ^ nums[i];
                nums[changePos] = nums[changePos] ^ nums[i];
                break;
            }
        }
        // 将新的最后一位与到changePos之间的各位比较，如果更大，就交换位置
        for(int i = numsSize - 1; i > changePos + 1; --i){
            if(nums[i] > nums[i - 1]){
                nums[i] = nums[i] ^ nums[i - 1];
                nums[i - 1] = nums[i] ^ nums[i - 1];
                nums[i] = nums[i] ^ nums[i - 1];
            }
        }
        // 将changPos之后的部分倒叙
        reverseArray(nums + changePos + 1, nums + numsSize - 1);
    }
}

int main(int argc, const char *argv[]){
    int nums[] = {1,3,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("before:\n\t");
    printArr(nums, numsSize);
    nextPermutation(nums, numsSize);
    printf("after:\n\t");
    printArr(nums, numsSize);
    return 0;
}