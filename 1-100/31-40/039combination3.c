

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int g_rstNum = 0;
int *g_colArr = NULL;
int **g_rst = NULL;

void dps(int* candidates, int candidatesSize, int target, int *tempArr, int depth, int sum, int index)
{
    // check
    if (sum > target) {
        return;
    }

    // set and save
    if (sum == target) {
        g_rst[g_rstNum] = (int *)malloc(sizeof(int) * depth);
        memcpy(g_rst[g_rstNum], tempArr, sizeof(int) * depth);
        g_colArr[g_rstNum] = depth;
        g_rstNum++;
    }

    // for dfs
    int i = 0;
    for (i = index; i < candidatesSize; i++) {
        tempArr[depth] = candidates[i];
        dps(candidates, candidatesSize, target, tempArr, depth + 1, sum + candidates[i], i);
    }

}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

    g_rstNum = 0;
    g_colArr = (int*)malloc(1000);
    g_rst = (int**)malloc(sizeof(int*) * 1000);

    int *tempArr = (int*)malloc(sizeof(int) * 1000);
    dps(candidates, candidatesSize, target, tempArr, 0, 0, 0);

    // return;
    *returnSize = g_rstNum;
    *returnColumnSizes = g_colArr;
    return g_rst;
}

int main(int argc, const char *argv[]){
    int candidates[] = {2,3,6,7};
    int target = 7;
    int returnSize;
    int *returnColumnSizes;
    int **combination = combinationSum((int *)candidates, sizeof(candidates)/sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; ++i){
        for(int j = 0; j < returnColumnSizes[i]; ++j){
            printf("%d, ", combination[i][j]);
        }
        printf("\n");
    }
    return 0;
}