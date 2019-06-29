#include "queue.h"
void queueTest(){
    int index = 1;
    int capacity = 5;
    SimpleQueue *queue = initQueue(capacity);
    // printf("%d.capacity = %d, size = %4d\n", index++, queue->capacity, queue->size);
    for(int i = 0; i < 10; ++i){
        queue->push(queue, i);
        printf("%d.capacity = %d, size = %4d\n", i+1, queue->capacity, queue->size);
    }
    // for(int i = 0; i < 1000; ++i){
    //     queue->push(queue, i);
    // }
    // printf("%d.capacity = %d, size = %4d\n", index++, queue->capacity, queue->size);
    queue->free_queue(queue);
}

int main(int argc, char *argv[]){
    queueTest();
    return 0;
}