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
    int len = strlen(s) + 1;
    printf("len = %d\n", len);
    char *str = (char *)malloc(len);
    // i 表示行， j 表示列
    int i = 0, j = 0, p = 0; 
    // PEAK表示每个循环的字符个数，如上边的注释中
    // PEAK = 2 * 3 - 2 = 4，即LEET  
    int PEAK = 2*numRows - 2;
    int peak = 0;
    int flag = 1;
    while(p < len - 1){
        if(i > 0 && i < numRows - 1){
            // 除了第一行和最后一行，每个PEAK循环每行有两个字符
            if(peak + i < len - 1)
                str[p++] = s[peak + i];
            if(peak + PEAK - i < len - 1){
                str[p++] = s[peak + PEAK - i];
            }
        }
        else{
            // 第一行和最后一行每次循环只有一个字符
            if(peak + i < len - 1)
                str[p++] = s[peak + i];
        }
        peak += PEAK;
        if(peak >= len - 1){
            peak = 0;
            ++i;
            continue;
        }
    }
    str[len-1] = '\0';
    return str;
}

int main(int argc, char *argv[]){

    char s[] = "ab";
    int numRows = 1;
    char *str = convert(s, numRows);
    printf("%s\n", str);
    return 0;
}