/*
机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：

-2：向左转 90 度
-1：向右转 90 度
1 <= x <= 9：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物。

如（2, 4)表示无法到达（2，4）坐标

如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。

返回从原点到机器人的最大欧式距离的平方(在二维空间上即终点到原点距离的平方)。

 

示例 1：

输入: commands = [4,-1,3], obstacles = []
输出: 25
解释: 机器人将会到达 (3, 4)
示例 2：

输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
输出: 65
解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 

提示：

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
答案保证小于 2 ^ 31
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dir[][3][2] = {
    {{},     {0,1},  {}},
    {{-1,0}, {0,0},  {1,0}},
    {{},     {0,-1}, {}}
};
int dil[][3][2] = {
    {{},    {0,-1}, {}},
    {{1,0}, {0,0},  {-1,0}},
    {{},    {0,1},  {}}
};
int findObstacleIndex(int ox, int oy, int x, int y, int dx, int dy, int *obstacles, int obstacleSize){
    int index = -1;
    int obsx, obsy;
    for(int i = 0; i < obstacleSize; ++i){
        obsx = obstacles[i*2+0]; 
        obsy = obstacles[i*2+1]; 
        if(obsx == 0 && obsy == 0)
            continue;
        if(dy > 0){
            // 向上
            if(obsx != x || obsy < oy || obsy > y)
                continue;
            if(index == -1){
                index = i;
            }
            else{
                if(obstacles[2*index+1] > obsy){
                    index = i;
                }
            }
        }
        else if(dy < 0){
            // 向下
            if(obsx != x || obsy > oy || obsy < y)
                continue;
            if(index == -1){
                index = i;
            }
            else{
                if(obstacles[2*index+1] < obsy){
                    index = i;
                }
            }
        }
        else if(dx < 0){
            // 向左
            if(obsy != y || obsx > ox || obsx < x)
                continue;
            printf("dx < 0, ox = %d, x = %d, obsx = %d\n", ox, x, obsx);
            if(index == -1){
                index = i;
            }
            else{
                if(obstacles[2*index+0] < obsx){
                    index = i;
                }
            }
        }
        else{
            // 向右
            if(obsy != y || obsx < ox || obsx > x)
                continue;
            if(index == -1){
                index = i;
            }
            else{
                if(obstacles[2*index+0] > obsx){
                    index = i;
                }
            }
        }
    }
    return index;
}
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize){
    int maxSqu = 0;
    int *obs = (int *)obstacles;
    int x = 0, y = 0;
    int *dr = NULL, *dl = NULL;
    int dx = 0, dy = 1;
    int index, moveInstance;
    int ox, oy;
    for(int i = 0; i < commandsSize; ++i){
        if(commands[i] == -1){
            // 右转
            dr = dir[1+dx][1+dy];
            dx = dr[0];
            dy = dr[1];
        }
        else if(commands[i] == -2){
            // 左转
            // printf("before turn left [%d, %d]\n", dx, dy);
            dl = dil[1+dx][1+dy];
            dx = dl[0];
            dy = dl[1];
            // printf("after  turn left [%d, %d]\n", dx, dy);
        }
        else{
            // 前进
            index = -1;
            moveInstance = commands[i];
            ox = x;
            oy = y;
            printf("dx = %d, dy = %d\n", dx, dy);
            x += commands[i] * dx;
            y += commands[i] * dy;
            for(int j = 0; j < obstaclesSize; ++j){
                index = findObstacleIndex(ox, oy, x, y, dx, dy, obs, obstaclesSize);
            }
            printf("x = %d, y = %d, index = %d\n", x, y, index);
            if(index != -1){
                // printf("index = %d\n", index);
                if(dx > 0){
                    printf("get obstacled 1\n");
                    x = obs[2*index+0] - 1;
                }
                else if(dx < 0){
                    printf("get obstacled 2\n");
                    x = obs[2*index+0] + 1;
                }
                else if(dy > 0){
                    printf("get obstacled 3\n");
                    y = obs[2*index+1] - 1;
                }
                else if(dy < 0){
                    printf("get obstacled 4\n");
                    y = obs[2*index+1] + 1;
                }
            }
            maxSqu = (maxSqu >= x*x+y*y ? maxSqu : x*x+y*y);
            printf("maxSqu = %d, %d, %d\n", maxSqu, x, y);
        }
    }
    return maxSqu; 
}
int main(int argc, const char *argv[]){
    // int commands[] = {-2, 8, 3, 7, -1};
    // int obstacles[][2] = {{-4,-1},{1,-1},{1,4},{5,0},{4,5},{-2,-1},{2,-5},{5,1},{-3,-1},{5,-3}};
    // int commands[] = {7,-2,-2,7,5};
    // int obstacles[][2] = {{-3,2},{-2,1},{0,1},{-2,4},{-1,0},{-2,-3},{0,-3},{4,4},{-3,3},{2,2}};
    // int commands[] = {4, -1, 4, -2, 4}; 
    // int obstacles[][2] = {{2, 4}}; 
    int commands[] = {-2,-1,-2,3,7};
    int obstacles[][2] = {{1,-3},{2,-3},{4,0},{-2,5},{-5,2},{0,0},{4,-4},{-2,-5},{-1,-2},{0,2}};
    int colSize = 2;
    int lenSqu = robotSim(commands, sizeof(commands)/sizeof(commands[0]), (int **)obstacles,
                    sizeof(obstacles)/sizeof(obstacles[0]), &colSize);
    printf("lenSqu = %d\n", lenSqu);
    return 0;
}