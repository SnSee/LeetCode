int **g_ans = NULL;
int g_index = 0;
int **permute(int *nums, int numsSize, int *returnSize)
{
    int num = 1;
    g_index = 0;
    for (int i = 1; i <= numsSize; ++i)
    {
        num = num * i;
    }
    g_ans = (int **)malloc(sizeof(int *) * num);
    recurPermute(nums, numsSize, 0);
    *returnSize = g_index;
    return g_ans;
}

int recurPermute(int *nums, int numsSize, int index)
{
    if (index == numsSize - 1)
    {
        g_ans[g_index] = NULL;
        g_ans[g_index] = (int *)malloc(sizeof(int) * numsSize);
        for (int i = 0; i != numsSize; ++i)
            g_ans[g_index][i] = nums[i];
        g_index++;
    }
    else
    {
        for (int j = index; j != numsSize; ++j)
        {
            int temp = nums[index];
            nums[index] = nums[j];
            nums[j] = temp;
            recurPermute(nums, numsSize, index + 1);
            nums[j] = nums[index];
            nums[index] = temp;
        }
    }
    return 0;
}