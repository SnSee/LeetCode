/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

                *                   *
                *===================*=======*
                *   *               *       *
                *   *       *       *       *
                *   *       *   *   *       *
                *   *       *   *   *   *   *
                *   *   *   *   *   *   *   *
            *   *===*===*===*===*===*===*===*
 

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

// 要点：从左右两侧同时向中间移动，外侧循环如果有最高的，比它低的不必再计算，内测循环同理，但要重置高度
// 时间复杂度也较高
#include<stdio.h>
#include<stdlib.h>
#define min(v1, v2) (v1 > v2 ? v2 : v1)
#define max(v1, v2) (v1 > v2 ? v1 : v2)
int maxArea(int* height, int heightSize){
    int maxArea = 0;
    int nowArea = 0;
    // 记录左侧已经计算的最高的，如果左侧数比最高的低，就无需再计算面积
    int highestLeft = 0;
    // 记录右侧已经计算的最高的，如果比最高的低，就无需再计算面积
    int highestRight = 0;
    for(int i = 0; i < heightSize; ++i){
        if(height[i] < highestLeft){
            continue;
        }
        highestLeft = height[i];
        // 下次循环重置最高高度
        highestRight = height[heightSize-1];
        for(int j = heightSize - 1; j > i; --j){
            if(height[j] < highestRight){
                continue;
            }
            highestRight = height[j];
            nowArea = (j - i) * min(height[i], height[j]);
            maxArea = max(maxArea, nowArea);
        }
    }
    return maxArea;
}
int main(int argc, char *argv[]){

    int num[] = {1,8,6,2,5,4,8,3,7};
    int area = maxArea(num, sizeof(num)/sizeof(num[0]));
    printf("area = %d\n", area);
    return 0;
}