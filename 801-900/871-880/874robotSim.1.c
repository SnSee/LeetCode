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
int findObstacleIndex(int ox, int oy, int x, int y, int dx, int dy, int **obstacles, int obstacleSize){
    int index = -1;
    int obsx, obsy;
    for(int i = 0; i < obstacleSize; ++i){
        obsx = obstacles[i][0]; 
        obsy = obstacles[i][1]; 
        if(dy > 0){
            // 向上
            if(obsx != x || obsy < oy || obsy > y)
                continue;
            if(index == -1){
                index = i;
            }
            else{
                if(obstacles[index][1] > obsy){
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
                if(obstacles[index][1] < obsy){
                    index = i;
                }
            }
        }
        else if(dx < 0){
            // 向左
            if(obsy != y || obsx > ox || obsx < x)
                continue;
            if(index == -1){
                index = i;
            }
            else{
                if(obstacles[index][0] < obsx){
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
                if(obstacles[index][0] > obsx){
                    index = i;
                }
            }
        }
    }
    return index;
}
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize){
    printf("obstacles = %p\n", obstacles);
    int maxSqu = 0;
    int **obs = obstacles;
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
            dl = dil[1+dx][1+dy];
            dx = dl[0];
            dy = dl[1];
        }
        else{
            // 前进
            index = -1;
            ox = x;
            oy = y;
            x += commands[i] * dx;
            y += commands[i] * dy;
            for(int j = 0; j < obstaclesSize; ++j){
                index = findObstacleIndex(ox, oy, x, y, dx, dy, obs, obstaclesSize);
            }
            if(index != -1)
                if(dx > 0 && x >= obs[index][0]){
                    x = obs[index][0] - 1;
                }
                else if(dx < 0 && x <= obs[index][0]){
                    x = obs[index][0] + 1;
                }
                else if(dy > 0 && y >= obs[index][1]){
                    y = obs[index][1] - 1;
                }
                else if(dy < 0 && y <= obs[index][1]){
                    y = obs[index][1] + 1;
                }
            }
            maxSqu = (maxSqu >= x*x+y*y ? maxSqu : x*x+y*y);
        }
    }
    return maxSqu; 
}
int main(int argc, const char *argv[]){
    int commands[] = {-2, 8, 3, 7, -1};
    int obstacles[][2] = {{-4,-1},{1,-1},{1,4},{5,0},{4,5},{-2,-1},{2,-5},{5,1},{-3,-1},{5,-3}};
    int colSize = 2;
    int lenSqu = robotSim(commands, sizeof(commands)/sizeof(commands[0]), (int **)obstacles,
                    sizeof(obstacles)/sizeof(obstacles[0]), &colSize);
    printf("lenSqu = %d\n", lenSqu);
    return 0;
}