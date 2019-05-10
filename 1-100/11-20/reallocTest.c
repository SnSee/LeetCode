
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

    int *aa = (int *)malloc(sizeof(int)*4);
    aa[0] = 10;
    aa = (int *)realloc(aa, sizeof(int)*10);
    printf("aa[0] = %d\n", aa[0]);
    return 0;
}