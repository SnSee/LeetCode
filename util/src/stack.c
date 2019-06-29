/*
 * 实现一个栈及部分操作(int类型)
 */

#include "stack.h"

void initStackMem(SimpleStack *simpleStack, int capacity){
    /* 
    栈容量控制在 1GB 以内 
    需要用户在使用后手动释放堆内存
    */
    if(capacity <= 0){
        capacity = DEFAULT_CAPACITY;
    }
    else if(capacity > MAX_CAPACITY){
        capacity = MAX_CAPACITY;
    }
    simpleStack->capacity = capacity;
    simpleStack->stack = (int *)malloc(sizeof(int) * capacity);
    memset(simpleStack->stack, 0, capacity);
}
void *myRealloc(void *ptr, int oldSize, int newSize){
    int *newPtr = (int *)malloc(sizeof(int) * newSize);
    memcpy(newPtr, ptr, oldSize);
    free(ptr);
    return newPtr;
}
void expendStackCapacity(SimpleStack *simpleStack){
    // 扩容
    if(simpleStack->size >= simpleStack->capacity){
        if(simpleStack->capacity < MAX_CAPACITY){
            int newCapacity = simpleStack->capacity * 2;
            if(newCapacity > MAX_CAPACITY){
                newCapacity = MAX_CAPACITY;
            }
            // simpleStack->stack = (int *)realloc(simpleStack->stack, newCapacity); 
            simpleStack->stack = myRealloc(simpleStack->stack, simpleStack->capacity, newCapacity);
            simpleStack->capacity = newCapacity;
        }
    }
}
void shrinkStackCapacity(SimpleStack *simpleStack){
    // 减少容量
    if(simpleStack->size > MIN_SHRINK_CAPACITY && simpleStack->size < simpleStack->capacity / 2){
        int newCapacity = simpleStack->capacity * 2 / 3;
        if(newCapacity < MIN_SHRINK_CAPACITY){
            newCapacity = MIN_SHRINK_CAPACITY;
        }
        simpleStack->stack = myRealloc(simpleStack->stack, simpleStack->capacity, newCapacity);
        simpleStack->capacity = newCapacity;
    }
}
int push(void *stack, int element){
    /* 入栈, 栈满时返回 -1 */
    SimpleStack *simpleStack = (SimpleStack *)stack;
    // 当容量不够时进行扩容
    expendStackCapacity(simpleStack);
    if(simpleStack->size < simpleStack->capacity){
        simpleStack->stack[simpleStack->size] = element;
        ++(simpleStack->size);
        return 0;
    }
    return -1;
}
int pop(void *stack){
    /* 出栈，无元素时不操作 */
    SimpleStack *simpleStack = (SimpleStack *)stack;
    if(simpleStack->size > 0){
        --(simpleStack->size);
    }
    else{
        return -1;
    }
    shrinkStackCapacity(simpleStack);
    return simpleStack->stack[simpleStack->size];
}
int top(void *stack){
    /* 获取栈顶元素的值，需要使用者自己保证size的值大于0，否则返回值不正确 */
    SimpleStack *simpleStack = (SimpleStack *)stack;
    if(simpleStack->size > 0){
        return simpleStack->stack[simpleStack->size - 1];
    }
    return -1;
}
int empty(void *stack){
    /* 如果是空栈返回 1，否则返回 0 */
    SimpleStack *simpleStack = (SimpleStack *)stack;
    if(simpleStack->size > 0){
        return 0;
    }
    return 1;
}
SimpleStack *initStack(int capacity){
    // 初始化栈
    // 释放空间时需要先释放simpleStack->stack，再释放simpleStack
    SimpleStack *simpleStack = (SimpleStack *)malloc(sizeof(SimpleStack));
    initStackMem(simpleStack, capacity);
    simpleStack->size = 0;
    simpleStack->push = push;
    simpleStack->pop = pop;
    simpleStack->top = top;
    simpleStack->empty = empty;
    return simpleStack;
}

void stackTest(){
    int top = 0;
    SimpleStack *stack = initStack(10);
    printf("after init ===================\n");
    printf("capacity = %d, size = %d\n", stack->capacity, stack->size);
    for(int i = 0; i < 272144; ++i){
        stack->push(&stack, i);
        // printf("size = %d\n", stack.size);
    }
    printf("after push ===================\n");
    printf("capacity = %d, size = %d\n", stack->capacity, stack->size);
    printf("top = %d\n", stack->top(&stack));
    while(stack->size > 0){
        // printf("top = %d\n", stack.top(&stack));
        stack->pop(&stack);
    }
    printf("after pop ===================\n");
    printf("capacity = %d, size = %d\n", stack->capacity, stack->size);
    free(stack->stack);
    stack->stack = NULL;
    free(stack);
    stack = NULL;
}
// int main(int argc, char *argv[]){
//     stackTest();
//     return 0;
// }