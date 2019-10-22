/*
二号解法，一次性遍历行列及九宫格
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    true=1, false=0
}bool;

// 本地运行
bool isValidSudoku2(char **board, int boardSize, int *boardColSize){
    // 二维数组行表示行数，列数及小九宫格，列用于存储本行，本列或本小九宫格已经出现过的数字(0表示没出现过，1表示出现过)
    char rowExist[9][9] = {0};
    char colExist[9][9] = {0};
    char boxExist[9][9] = {0};
    char *boardT = (char *)board;
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardSize; ++j){
            // 将字符的数字转换成实际的数字，就可以当做下标进行访问数组
            if('.' == boardT[i * boardSize + j])
                continue;
            int num = boardT[i * boardSize + j] - '1';
            int index = i / 3 * 3 + j / 3;
            // printf("num = %d, i = %d, j = %d, index = %d\n", num, i, j, index);
            if(rowExist[i][num] || colExist[j][num] || boxExist[index][num]){
                printf("return false i = %d, j = %d, index = %d, num = %d\n", i, j, index, num);
                printf("row = %d, col = %d, box = %d\n", rowExist[i][num], colExist[j][num], boxExist[index][num]);
                return false;
            }
            rowExist[i][num] = 1;
            colExist[j][num] = 1;
            boxExist[index][num] = 1;
        }
    }
    return true;
}

// LeetCode提交
bool isValidSudoku(char **board, int boardSize, int *boardColSize){
    // 二维数组行表示行数，列数及小九宫格，列用于存储本行，本列或本小九宫格已经出现过的数字(0表示没出现过，1表示出现过)
    char rowExist[9][9] = {0};
    char colExist[9][9] = {0};
    char boxExist[9][9] = {0};
    for(int i = 0; i < boardSize; ++i){
        for(int j = 0; j < boardSize; ++j){
            if('.' == board[i][j]){
                continue;
            }
            // 将字符的数字转换成实际的数字，就可以当做下标进行访问数组
            int num = board[i][j] - '1';
            int index = i / 3 * 3 + j / 3;
            if(rowExist[i][num] || colExist[j][num] || boxExist[index][num]){
                return false;
            }
            rowExist[i][num] = 1;
            colExist[j][num] = 1;
            boxExist[index][num] = 1;
        }
    }
    return true;
}

int main(int argc, const char *argv[]){
    char sudoku[9][9] = {
        {'5', '3', '.',    '.', '7', '.',    '.', '.', '.'},
        {'6', '.', '.',    '1', '9', '5',    '.', '.', '.'},
        {'.', '9', '8',    '.', '.', '.',    '.', '6', '.'},

        {'8', '.', '.',    '.', '6', '.',    '.', '.', '3'},
        {'4', '.', '.',    '8', '.', '3',    '.', '.', '1'},
        {'7', '.', '.',    '.', '2', '.',    '.', '.', '6'},

        {'.', '6', '.',    '.', '.', '.',    '2', '8', '.'},
        {'.', '.', '.',    '4', '1', '9',    '.', '.', '5'},
        {'.', '.', '.',    '.', '8', '.',    '.', '7', '.'}};
    int i = 0;
    if (isValidSudoku2((char **)sudoku, 9, &i))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}