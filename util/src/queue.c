#include "queue.h"
void initQueueMem(SimpleQueue *simpleQueue, int capacity){
    /* 
    队列容量控制在 1GB 以内 
    需要用户在使用后手动释放堆内存
    */
    if(capacity <= 0){
        capacity = DEFAULT_CAPACITY; 
    }
    if(capacity > MAX_CAPACITY){
        capacity = MAX_CAPACITY;
    }
    simpleQueue->original_head = (int *)malloc(sizeof(int) * capacity);
    memset(simpleQueue->original_head, 0, capacity);
}
void *myRealloc(void *ptr, int oldSize, int newSize){
    int *newPtr = (int *)malloc(sizeof(int) * newSize);
    memcpy(newPtr, ptr, oldSize);
    free(ptr);
    return newPtr;
}
void moveTail(SimpleQueue *simpleQueue, int space_head, int space_tail){
    if(space_head < space_tail){
        return;
    }
    simpleQueue->queue_head = simpleQueue->original_head + space_head;
    int oldCapacity = simpleQueue->capacity / 2;
    int *original_tail = simpleQueue->original_head + oldCapacity;
    for(int i = 0; i < space_tail; ++i){
        *original_tail = *(simpleQueue->original_head + i);
        ++original_tail;
    }
    simpleQueue->queue_tail = simpleQueue->queue_head + simpleQueue->size;
}
void expendQueueCapacity(SimpleQueue *simpleQueue){
    // 扩容
    int space_head = 0;     // queue_head指针到original_head的距离
    int space_tail = 0;     // queue_tail指针到original_head的距离
    if(simpleQueue->size >= simpleQueue->capacity){
        if(simpleQueue->capacity < MAX_CAPACITY){
            int newCapacity = simpleQueue->capacity * 2;
            if(newCapacity > MAX_CAPACITY){
                newCapacity = MAX_CAPACITY;
            }
            simpleQueue->original_head = myRealloc(simpleQueue->original_head, simpleQueue->capacity, newCapacity);
            simpleQueue->capacity = newCapacity;
            // 将在queue_head前的元素移动到后面
            if(simpleQueue->queue_head > simpleQueue->queue_tail){
                space_head = simpleQueue->queue_head - simpleQueue->original_head;
                space_tail = simpleQueue->queue_tail - simpleQueue->original_head;
                moveTail(simpleQueue, space_head, space_tail);
            }
        }
    }
}
void shrinkQueueCapacity(SimpleQueue *simpleQueue){
    // 减少容量
    int space_head = simpleQueue->queue_head - simpleQueue->original_head;
    int space_tail = simpleQueue->queue_tail - simpleQueue->original_head;
    if(simpleQueue->size > MIN_SHRINK_CAPACITY && simpleQueue->size < simpleQueue->capacity / 2){
        int newCapacity = simpleQueue->capacity * 2 / 3;
        if(newCapacity < MIN_SHRINK_CAPACITY){
            newCapacity = MIN_SHRINK_CAPACITY;
        }
        simpleQueue->original_head = myRealloc(simpleQueue->original_head, simpleQueue->capacity, newCapacity);
        simpleQueue->capacity = newCapacity;
        // 重定位头尾节点指针
        simpleQueue->queue_head = simpleQueue->original_head + space_head;
        simpleQueue->queue_tail = simpleQueue->original_head + space_tail;
    }
}
int push(void *queue, int element){
    /* 入队，队满返回-1 */
    SimpleQueue *simpleQueue = (SimpleQueue *)queue;
    expendQueueCapacity(simpleQueue);
    if(simpleQueue->size < simpleQueue->capacity){
        *(simpleQueue->queue_tail) = element;
        ++(simpleQueue->queue_tail);
        ++(simpleQueue->size);
        return 0;
    }
    return -1;
}
int pop(void *queue){
    SimpleQueue *simpleQueue = (SimpleQueue *)queue;
    int headElement;
    if(simpleQueue->size > 0){
        --(simpleQueue->size);
    }
    else{
        return -1;
    }
    headElement = *(simpleQueue->queue_head);
    if(simpleQueue->queue_head != simpleQueue->original_head + simpleQueue->capacity - 1){
        ++(simpleQueue->queue_head);
    }
    else{
        simpleQueue->queue_head = simpleQueue->original_head;
    }
    shrinkQueueCapacity(simpleQueue);
    return headElement;
}
void free_queue(void *queue){
    SimpleQueue *simpleQueue = (SimpleQueue *)queue;
    if(NULL != simpleQueue->original_head){
        free(simpleQueue->original_head);
        simpleQueue->original_head = NULL;
    }
}
SimpleQueue *initQueue(int capacity){
    SimpleQueue *simpleQueue = NULL;
    initQueueMem(simpleQueue, capacity);
    simpleQueue->queue_head = simpleQueue->original_head;
    simpleQueue->queue_tail = simpleQueue->original_head;
    simpleQueue->capacity = capacity;
    simpleQueue->size = 0;
    simpleQueue->push = NULL;
    simpleQueue->pop = NULL;
    simpleQueue->top = NULL;
    simpleQueue->empty = NULL;
    return simpleQueue;
}

