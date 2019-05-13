/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，
都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。
如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

注意：

你可以假设胃口值为正。
一个小朋友最多只能拥有一块饼干。

示例 1:

输入: [1,2,3], [1,1]

输出: 1

解释: 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
示例 2:

输入: [1,2], [1,2,3]

输出: 2

解释: 
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出2.
*/

#include <stdio.h>
#include <stdlib.h>
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
int findContentChildren(int* g, int gSize, int* s, int sSize){
    int count = 0;
    int posJ = -1;
    sort(g, g + gSize - 1);
    sort(s, s + sSize - 1);
    int i = 0, j = 0;
    while(i < gSize && j < sSize){
        while(s[j] < g[i]){
            ++j;
            if(j == sSize)
                return count;
        }
        ++count;
        ++i;
        ++j;
    } 
    return count;
}

int main(int argc, char *argv[]){
    int g[] = {1, 2, 3};
    int s[] = {3};
    int count = findContentChildren(g, sizeof(g)/sizeof(g[0]), s, sizeof(s)/sizeof(s[0]));
    printf("count = %d\n", count);
    return 0;
}