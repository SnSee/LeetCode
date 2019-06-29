/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/
int searchPos(int *nums, int numsSize, int start, int end, int target){
    int pos = start + (end - start) / 2;
    if(target == nums[pos]){
        return pos;
    }
    searchPos(nums, numsSize, start, pos - 1, target);
    searchPos(nums, numsSize, pos + 1, end, target);
    return pos;
}
int searchInsert(int* nums, int numsSize, int target){
    int start = 0, end = numsSize - 1;
    int pos = (start + end) / 2;
    int space = (start + end) / 2;
    while(1){
        space /= 2;
        if(nums[pos] == target){
            return pos;
        }
        if(space == 0){
            
        }
        if(nums[pos] > target){
            pos -= space;
        }
        else{
            pos += space;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 7;
    int pos = searchInsert(nums, numsSize, target);
    printf("pos = %d\n", pos);
    return 0;
}