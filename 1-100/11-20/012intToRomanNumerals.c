/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
#include<stdio.h>
#include<stdlib.h>
char* intToRoman(int num) {
    char *romanNum = (char *)malloc(20);
    int i = -1;
    while(1){
        ++i;
        if(num >= 1000){
            num -= 1000;
            romanNum[i] = 'M';
        }
        else if(num >= 900){
            num -= 900;
            romanNum[i] = 'C';
            romanNum[++i] = 'M';
        }
        else if(num >= 500){
            num -= 500;
            romanNum[i] = 'D';
        }
        else if(num >= 400){
            num -= 400;
            romanNum[i] = 'C';
            romanNum[++i] = 'D';
        }
        else if(num >= 100){
            num -= 100;
            romanNum[i] = 'C';
        }
        else if(num >= 90){
            num -= 90;
            romanNum[i] = 'X';
            romanNum[++i] = 'C';
        }
        else if(num >= 50){
            num -= 50;
            romanNum[i] = 'L';
        }
        else if(num >= 40){
            num -= 40;
            romanNum[i] = 'X';
            romanNum[++i] = 'L';
        }
        else if(num >= 10){
            num -= 10;
            romanNum[i] = 'X';
        }
        else if(num >= 9){
            num -= 9;
            romanNum[i] = 'I';
            romanNum[++i] = 'X';
        }
        else if(num >= 5){
            num -= 5;
            romanNum[i] = 'V';
        }
        else if(num >= 4){
            num -= 4;
            romanNum[i] = 'I';
            romanNum[++i] = 'V';
        }
        else if(num >= 1){
            num -= 1;
            romanNum[i] = 'I';
        }
        else{
            break;
        }
    }
    romanNum[i] = '\0';
    return romanNum;
}
int main(int argc, char *argv[]){

    int num = 0;
    char *romanNum;
    while(1){
        scanf("%d", &num);
        romanNum = intToRoman(num);
        printf("romanNum = %s\n", romanNum);
    }

    return 0;
}