/*
 * 将多个节点合并成一个有序链表, 顺序为从小打大
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
int compareNodeLE(struct ListNode *l1, struct ListNode *l2){
    if(NULL == l1 || NULL == l2){
        return -1;
    }
    return l1->val <= l2->val;
}
struct ListNode *insertNodeByOrder(struct ListNode *head, struct ListNode *node){
    if(NULL == node){
        return head;
    }
    struct ListNode headNode = {0, head};
    struct ListNode *p = &headNode;
    int flag = 0;
    while(NULL != p->next){
        // printf("p->next = %p\n", p->next);
        if(compareNodeLE(node, p->next)){
            node->next = p->next;
            p->next = node;
            flag = 1;
            break;
        }
        p = p->next;
    }
    if(!flag){
        p->next = node;
    }
    return headNode.next;
}
struct ListNode *mergeNodesToOrderedList(struct ListNode **nodes, int nodeSize){
    struct ListNode *head = NULL;
    for(int i = 0; i < nodeSize; ++i){
        head = insertNodeByOrder(head, nodes[i]);
    }
    return head;
}
void printList(struct ListNode *head){
    struct ListNode *p = head;
    while(NULL != p){
        printf("%d, ", p->val);
        p = p->next;
    }
    printf("\n");
}
void printListNodes(struct ListNode **nodes, int size){
    for(int i = 0; i < size; ++i){
        printf("%d, %p\n", nodes[i]->val, nodes[i]->next);
    }
    printf("\n");
}
int main(int argc, char *argv[]){
    int n = 6;
    struct ListNode **nodes = (struct ListNode **)malloc(sizeof(struct ListNode *) * n);
    for(int i = 0; i < n; ++i){
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i;
        node->next = NULL;
        nodes[i] = node;
    }
    nodes[5] = NULL;
    // printListNodes(nodes, n);
    struct ListNode *head = mergeNodesToOrderedList(nodes, n);
    printList(head);

    for(int i = 0; i < n; ++i){
        free(nodes[i]);
    }
    free(nodes);
    return 0;
}