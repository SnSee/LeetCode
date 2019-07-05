/*
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printMatrix(int **matrix2, int matrixSize){
    int *matrix = (int *)matrix2;
    for(int i = 0; i < matrixSize; ++i){
        for(int j = 0; j < matrixSize; ++j){
            printf("%d, ", matrix[matrixSize * i + j]);
        }
        printf("\n");
    }
}
void printArray2(int *array, int rowSize, int columnSize){
    for(int i = 0; i < rowSize; ++i){
        for(int j = 0; j < columnSize; ++j){
            printf("%d, ", array[columnSize * i + j]);
        }
        printf("\n");
    }
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int tempSize = matrixSize;
    int loopCount = 0;
    int temp = 0;
    // 先转外圈，逐层转到内圈
    while(loopCount <= matrixSize/2){
        for(int i = 0; i < tempSize - 1; ++i){
            // printf("loopCount = %d, i = %d\n", loopCount, i);
            // printArray2((int *)coor, 4, 2);
            // printf("after assign coor\n");
            temp = matrix[loopCount][loopCount + i];
            matrix[loopCount][loopCount + i] = matrix[matrixSize - 1 - loopCount - i][loopCount];
            matrix[matrixSize - 1 - loopCount - i][loopCount] = matrix[matrixSize - 1 - loopCount][matrixSize - 1 - loopCount - i];
            matrix[matrixSize - 1 - loopCount][matrixSize - 1 - loopCount - i] = matrix[loopCount + i][matrixSize - 1 - loopCount];
            matrix[loopCount + i][matrixSize - 1 - loopCount] = temp;
        }
        // printf("========== matrix in while ==========\n");
        // printMatrix((int **)matrix, matrixSize);
        tempSize -= 2;
        ++loopCount;
    }
}
int main(int argc, const char *argv[]){
    int matrix[][3] = {{7, 4, 1},
                       {8, 5, 2},
                       {9, 6, 3}
                      };
    // int matrix[][4] = {
    //                     {5, 1, 9, 11},
    //                     {2, 4, 8, 10},
    //                     {13, 3, 6, 7},
    //                     {15, 14, 12, 16}
    // };
    int matrixSize = sizeof(matrix)/sizeof(matrix[0]);
    printf("=======before rotate=========\n");
    printMatrix((int **)matrix, matrixSize);
    printf("=======after  rotate=========\n");
    rotate((int **)matrix, matrixSize, (void *)0);
    printMatrix((int **)matrix, matrixSize);
    return 0;
}