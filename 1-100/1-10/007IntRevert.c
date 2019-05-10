/* 对于给定的32位以内的有符号整数，反转各个进位，如将-1230转换为-321
*/
#include <stdio.h>

int reverse(int x){
    long ret = 0, y = x;
    int units = 0;
    char flag = 1;
    long MAX_NUM = 2147483647;
    // 记录y的符号位并使y始终为正数
    if(y < 0){
        flag = 0;
        y = -y;
    }
    //printf("x = %d\n", x);
    //printf("y = %ld\n", y);
    while(y >= 1){
        units = y % 10;
        y /= 10;
        ret = ret * 10 + units;
    }
    //printf("ret = %ld\n", ret);
    if(flag && ret >MAX_NUM)
        return 0;
    if(!flag && ret > MAX_NUM + 1)
        return 0;
    return (flag ? (int)ret : -(int)ret);
}

int main(int argc, char *argv[]){

    int ret = reverse(-2147483648);
    printf("ret = %d\n", ret);

    return 0;
}