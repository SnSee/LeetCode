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

// 要点：从左右两侧同时开始，但是只移动较矮的一侧，时间复杂度为O(n)，索引版
#include<stdio.h>
#include<stdlib.h>
#define min(v1, v2) (v1 > v2 ? v2 : v1)
#define max(v1, v2) (v1 > v2 ? v1 : v2)
int maxArea(int* height, int heightSize){
    int maxArea = 0;
    int nowArea = 0;
    int left = 0, right = heightSize - 1; 
    // 可以不记录tempHighLeft和tempHighRight
    int tempHighLeft = 0, tempHighRight = 0;
    while(left < right){
        if(height[left] < height[right]){
            if(height[left] < tempHighLeft){
                ++left;
                continue;
            }
            tempHighLeft = height[left];
            nowArea = height[left] * (right - left);
            maxArea = max(nowArea, maxArea);
            ++left;
        } 
        else{
            if(height[right] < tempHighRight){
                --right;
                continue;
            }
            tempHighRight = height[right];
            nowArea = height[right] * (right - left);
            maxArea = max(nowArea, maxArea);
            --right;
        }
    }
    return maxArea;
}
int main(int argc, char *argv[]){

    int num[] = {1, 2, 3};
    int area = maxArea(num, sizeof(num)/sizeof(num[0]));
    printf("area = %d\n", area);
    return 0;
}