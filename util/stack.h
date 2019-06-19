#ifndef __stack__
#define __stack__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*pFunc_push)(void *, int);
typedef void (*pFunc_pop)(void *);
typedef int (*pFunc_top)(void *);
typedef struct _simpleStack{
    int *stack;     // 需要调用 initStack()进行初始化
    int capacity;   // 能容纳的元素总数 
    int size;       // 实际元素个数
    pFunc_push push;    // 入栈操作
    pFunc_pop pop;      // 出栈操作
    pFunc_top top;      // 获取栈顶元素
}SimpleStack;

void initStack(SimpleStack *simpleStack, int capacity);
#endif