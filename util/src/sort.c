#include "stack.h"
#include <time.h>
#define SIZE 100
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

// 把startIndex到endIndex分成两部分，是左侧都小于pivot的值，右侧都大于pivot的值
int partition(int *nums, int startIndex, int endIndex){
    if(startIndex >= endIndex){
        return startIndex;
    }
    int pivotIndex = startIndex + (endIndex - startIndex) / 2;
    int pivot = nums[pivotIndex];
    // 将基准值移到数组开头
    nums[pivotIndex] = nums[startIndex];
    nums[startIndex] = pivot;
    while(startIndex < endIndex){
        while(startIndex < endIndex && pivot <= nums[endIndex]){
            --endIndex;
        }
        nums[startIndex] = nums[endIndex];
        while(startIndex < endIndex && pivot >= nums[startIndex]){
            ++startIndex;
        }
        nums[endIndex] = nums[startIndex];
    }
    nums[startIndex] = pivot;
    return startIndex;
}
void printArray(int *, int);
// 快速排序栈版
void sort_by_stack(int *nums, int size){
    // 创建栈
    int startIndex = 0;
    int endIndex = size - 1;
    SimpleStack *stack = initStack(size);
    stack->push(stack, endIndex);
    stack->push(stack, startIndex);
    while(!stack->empty(stack)){
        int start = stack->pop(stack);
        int end = stack->pop(stack);
        int pivotIndex = partition(nums, start, end);
        if(start < pivotIndex - 1){
            // 注意是start后入栈
            stack->push(stack, pivotIndex - 1);
            stack->push(stack, start);
        }
        if(pivotIndex + 1 < end){
            stack->push(stack, end);
            stack->push(stack, pivotIndex + 1);
        }
        // printArray(nums, size);
    }
    free(stack);
}

void printArray(int *nums, int size){
    for(int i = 0; i < size; ++i){
        printf("%d, ", nums[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[]){
    srand(20);
    // int nums[] = {5, 4, 6, 8 ,1 ,2};
    // int nums[] = {8, 7, 6, 5, 4, 3, 2, 1};
    // int nums[] = {5, 4, 3, 2, 1};
    srand((unsigned)time(NULL));
    int nums[SIZE];
    for(int i = 0; i < SIZE; ++i){
        nums[i] = rand() % 100;
    }
    int size = sizeof(nums)/sizeof(nums[0]);
    printf("before sort==========\n");
    printArray(nums, size);
    sort_by_stack(nums, size);
    printf("after sort==========\n");
    printArray(nums, size);
    return 0;
}