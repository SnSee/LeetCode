/* 对于给定的32位以内的有符号整数，反转各个进位，如将-1230转换为-321
*/
#include <stdio.h>

int reverse(int x){
    int ret = 0;
    int units = 0;
    int MAX_NUM = 2147483647;
    int MIN_NUM = -2147483648;

    while(x != 0){
        units = x % 10;
        x /= 10;
        if(ret > MAX_NUM/10 || (ret == MAX_NUM/10 && units>7)){
            return 0;
        }
        if(ret < MIN_NUM/10 || (ret == MIN_NUM/10 && units<-8)){
            return 0;
        }
        ret = ret * 10 + units;
    }
    return ret;
}

int main(int argc, char *argv[]){

    int ret = reverse(2147483647);
    printf("ret = %d\n", ret);

    return 0;
}
