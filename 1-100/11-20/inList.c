#include <stdio.h>
#include <stdlib.h>
int inList(int **sums, int size, int *num){
    for(int i = 0; i < size; ++i){
        if(sums[i][0] == num[0]){
            if(sums[i][1] == num[1]){
                if(sums[i][2] == num[2]){
                    return 1;
                }
            }
        }
        else if(sums[i][0] < num[0]){
            return 0;
        }
    }
    printf("==========inList\n");
    return 0;
}

int main(int argc, char *argv[]){
    int count = 2;
    int **sums = (int **)malloc(sizeof(int *)*count);
    sums[0] = (int *)malloc(sizeof(int) * 3);
    sums[0][0] = -1;
    sums[0][1] = 0;
    sums[0][2] = 1;
    int num[3] = {-2, 0, 2};
    int in = inList((int **)sums, 1, num);
    if(in){
        printf("in\n");
    }
    else{
        printf("not in\n");
    }
    return 0;
}