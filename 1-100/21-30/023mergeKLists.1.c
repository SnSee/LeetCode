/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct _indexOrder{
    int index;
    struct _indexOrder *next;
}indexOrder;
void printList(struct ListNode *node){
    while(node){
        printf("%d, ", node->val);
        node = node->next;
    }
    printf("\n");
}
indexOrder *pHead = NULL;
int nullCount = 0;
int init = 0;
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
void initOrderNodes(struct ListNode **nodes, int size){
    pHead = (indexOrder *)malloc(sizeof(indexOrder) * size);
    memset(pHead, 0, sizeof(indexOrder) * size);
    if(!init){
        indexOrder *p = pHead;
        // 全部填充为有序节点
        struct ListNode *head = mergeNodesToOrderedList(nodes, size);
        init = 1;
    }
}
int findLowestNode(struct ListNode **nodes, int size){
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(!listsSize){
        return NULL;
    }
    struct ListNode headNode = {0, NULL};
    struct ListNode *p = &headNode;
    struct ListNode **nodes = (struct ListNode **)malloc(sizeof(struct ListNode*) * listsSize);
    int index;
    for(int i = 0; i < listsSize; ++i){
        // 记录所有头结点
        nodes[i] = lists[i];
        // printList(nodes[i]);
    }
    while(1){
        index = findLowestNode(nodes, listsSize);
        // printf("index = %d\n", index);
        if(index >= listsSize){
            break;
        }
        p->next = nodes[index];
        p = p->next;
        // 由于如果是NULL，不会返回相应的index，多有不用担心会出现NULL->next
        nodes[index] = nodes[index]->next;
        // printList(headNode.next);
    }
    return headNode.next;
}
int main(int argc, const char *argv[]){
    int n = 3;
    // 构建链表
    struct ListNode l13 = {5, NULL};
    struct ListNode l12 = {4, &l13};
    struct ListNode l11 = {1, &l12};

    struct ListNode l23 = {4, NULL};
    struct ListNode l22 = {3, &l23};
    struct ListNode l21 = {1, &l22};

    struct ListNode l32 = {6, NULL};
    struct ListNode l31 = {2, &l32};

    struct ListNode *lists[3] = {&l11, &l21, &l31};
    struct ListNode *newHead;
    newHead = mergeKLists(NULL, 0);
    printList(newHead); 
    return 0;
}