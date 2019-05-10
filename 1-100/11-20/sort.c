

#include <stdio.h>
//打印一维数组
void printArray1(int *nums, int numsSize){
    printf("[");
    for(int i = 0; i < numsSize; ++i){
        printf("%d, ", nums[i]);
    }
    printf("]\n");
}
// 打印一维数组
void printArray2(int *start, int *end){
    printf("[");
    while(start <= end){
        printf("%d, ", *start);
        ++start;
    }
    printf("]\n");
}
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

int main(int argc, char *argv[]){

    int num[] = {3, 4, 1, 2, 5, 6};
    int len = sizeof(num)/sizeof(num[0]);
    sort(num, num + len - 1);
    printArray1(num, len);
    return 0;
}