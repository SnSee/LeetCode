/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: true
示例 2:

输入:
[
  ['8','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    true=1, false=0
}bool;

char numExist[10] = {0};
int rowCount = 0;
int columnCount = 0;

// 一行中是否有重复的数字
bool validRow1(char *row, int rowSize){
    memset(numExist, 0, 10);
    printf("rowCount=%d\n", rowCount++);
    for(int i = 0; i < rowSize; ++i){
        if('.' == row[i])
            continue;
        // printf("row[i] - '0' = %d, row[i]=%c\n", row[i] - '0', row[i]);
        if(numExist[row[i] - '0']){
            return false;
        }
        numExist[row[i] - '0'] = 1;
    }
    return true;
}

// 一列中是否有重复数字，本地运行
bool validColumn1(char **board, int boardSize, int column){
    printf("columnCount=%d\n", columnCount++);
    memset(numExist, 0, 10);
    char *boardT = (char *)board;
    for(int i = 0; i < boardSize; ++i){
        if('.' == boardT[boardSize * i + column])
            continue;
        printf("column[i] - '0' = %d\n", boardT[boardSize * i + column] - '0');
        if(numExist[boardT[boardSize * i + column] - '0']){
            return false;
        }
        numExist[boardT[boardSize * i + column] - '0'] = 1;
    }
    return true;
}

// 九宫格中是否有重复数据，本地运行
bool validBox1(char **board, int boardSize, int rowStart, int columnStart){
    memset(numExist, 0, 10);
    char *boardT = (char *)board;
    for(int i = rowStart; i < rowStart + 3; ++i){
        for(int j = columnStart; j < columnStart + 3; ++j){
            if('.' == boardT[boardSize * i + j])
                continue;
            // printf("column[i] - '0' = %d\n", boardT[boardSize * i + j] - '0');
            if(numExist[boardT[boardSize * i + j] - '0']){
                return false;
            }
            numExist[boardT[boardSize * i + j] - '0'] = 1;
        }
    }
    return true;
}

// 一行中是否有重复的数字 LeetCode提交
bool validRow2(char *row, int rowSize){
    memset(numExist, 0, 10);
    printf("rowCount=%d\n", rowCount++);
    for(int i = 0; i < rowSize; ++i){
        if('.' == row[i])
            continue;
        // printf("row[i] - '0' = %d, row[i]=%c\n", row[i] - '0', row[i]);
        if(numExist[row[i] - '0']){
            return false;
        }
        numExist[row[i] - '0'] = 1;
    }
    return true;
}

// 九宫格中是否有重复数据，LeetCode提交
bool validBox2(char **board, int boardSize, int rowStart, int columnStart){
    memset(numExist, 0, 10);
    for(int i = rowStart; i < rowStart + 3; ++i){
        for(int j = columnStart; j < columnStart + 3; ++j){
            if('.' == board[i][j])
                continue;
            if(numExist[board[i][j] - '0']){
                return false;
            }
            numExist[board[i][j] - '0'] = 1;
        }
    }
    return true;
}

// 一列中是否有重复数字，LeetCode提交，
bool validColumn2(char **board, int boardSize, int column)
{
    memset(numExist, 0, 10);
    for(int i = 0; i < boardSize; ++i){
        if('.' == board[i][column])
            continue;
        if(numExist[board[i][column] - '0']){
            return false;
        }
        numExist[board[i][column] - '0'] = 1;
    }
    return true;
}

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    for (int i = 0; i < 9; ++i)
    {
        if (!validRow2(board[i], boardSize))
        {
            return false;
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        if (!validColumn2(board, boardSize, i))
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            if (!validBox2(board, boardSize, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

bool isValidSudoku2(char **board, int boardSize, int *boardColSize)
{
    char *boardT = (char *)board;
    for (int i = 0; i < 9; ++i)
    {
        if (!validRow1(boardT + boardSize * i, boardSize))
        {
            return false;
        }
    }
    for (int i = 0; i < 9; ++i)
    {
        if (!validColumn1(board, boardSize, i))
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            if (!validBox1(board, boardSize, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    char sudoku[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '2'}};
    int i = 0;
    if (isValidSudoku((char **)sudoku, 9, &i))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}