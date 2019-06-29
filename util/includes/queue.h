#ifndef __queue__
#define __queue__
#define DEFAULT_CAPACITY 100
#define MAX_CAPACITY 262144
#define MIN_SHRINK_CAPACITY 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int (*pFunc_push)(void *, int);
typedef int (*pFunc_pop)(void *);
typedef int (*pFunc_top)(void *);
typedef int (*pFunc_empty)(void *);
typedef void (*pFunc_free)(void *);
typedef struct _simpleQueue{
    int *original_head;     // 原始的队列头，用于清空和申请新内存操作
    int *queue_head;     // 队列头，需要调用 initStack()进行初始化
    int *queue_tail;    // 队列尾
    int capacity;   // 能容纳的元素总数 
    int size;       // 实际元素个数
    pFunc_push push;    // 入队列操作
    pFunc_pop pop;      // 出队列操作
    pFunc_top top;      // 获取队列头元素
    pFunc_empty empty;  // 是否是空队列
    pFunc_free free_queue;  // 释放内存
}SimpleQueue;

SimpleQueue *initQueue(int capacity);
#endif