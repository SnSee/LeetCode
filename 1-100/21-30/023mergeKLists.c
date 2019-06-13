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
void printList(struct ListNode *node){
    while(node){
        printf("%d, ", node->val);
        node = node->next;
    }
    printf("\n");
}
int findLowestNode(struct ListNode **nodes, int size){
    // 空节点比非空节点大
    int index = -1;
    int minIndex = 0;
    // 找到第一个非空节点
    for(; minIndex < size; ++minIndex){
        if(NULL != nodes[minIndex]){
            break;
        }
    }
    // printf("minIndex = %d\n", minIndex);
    for(index = minIndex; index < size; ++index){
        if(NULL != nodes[index] && nodes[index]->val < nodes[minIndex]->val){
            minIndex = index;
        }
    }
    // 如果所有节点都是空节点，返回size
    return minIndex;
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