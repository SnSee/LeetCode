/* 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if(numRows == 1)
        return s;
    int len = strlen(s);
    char *str = (char *)malloc(len + 1);
    // i 表示行， j 表示列
    int i, p = 0; 
    // PEAK表示每个循环的字符个数，如上边的注释中
    // PEAK = 2 * 3 - 2 = 4，即LEET  
    int span = 2*numRows - 2;
    // start是有多行的列的坐标，start2是只有一行的列的坐标
    int start, start2;
    int nT = numRows - 1;
    for(i = 0; i < numRows; ++i){
        start = i;
        start2 = span - i;
        while(start < len){
            if(start < len){
                str[p++] = s[start];
                start += span;
            }
            if(i > 0 && i < nT && start2 < len){
                str[p++] = s[start2];
                start2 += span;
            }
        } 
    }
    
    str[len] = '\0';
    return str;
}

int main(int argc, char *argv[]){

    char s[] = "PAYPALISHIRING";
    int numRows = 3;
    char *str = convert(s, numRows);
    printf("%s\n", str);
    return 0;
}