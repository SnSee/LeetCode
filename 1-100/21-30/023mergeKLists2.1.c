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

int firstLT(struct ListNode *n1, struct ListNode *n2){
    if(n1 == NULL){
        return 1;
    }
    else if(n2 == NULL){
        return 0;
    }
    if(n1->val >= n2->val){
        return 0;
    }
    return 1;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    struct ListNode *nl1 = l1;
    struct ListNode *nl2 = l2;
    struct ListNode *newL = NULL;
    struct ListNode *head = NULL;
    // 处理头指针
    if(firstLT(nl1, nl2)){
        newL = nl1;
        nl1 = nl1->next;
    }
    else{
        newL = nl2;
        nl2 = nl2->next;
    }
    head = newL;
    // 处理其他节点
    while(nl1 != NULL && nl2 != NULL){
        if(firstLT(nl1, nl2)){
            newL->next = nl1;
            nl1 = nl1->next;
        }
        else{
            newL->next = nl2;
            nl2 = nl2->next;
        }
        newL = newL->next;
    } 
    if(nl1 == NULL){
        newL->next = nl2;
    }
    else if(nl2 == NULL){
        newL->next = nl1;
    }
    return head;
}
struct ListNode *mergeLists(struct ListNode **lists, int listSize){
    if(listSize == 1){
        return lists[0];
    }
    int leftSize = listSize/2;
    int rightSize = listSize - leftSize;
    struct ListNode *left = mergeLists(lists, listSize/2);
    struct ListNode *right = mergeLists(lists+leftSize, rightSize);
    return mergeTwoLists(left, right);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(!listsSize){
        return NULL;
    }
    return mergeLists(lists, listsSize);
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
    newHead = mergeKLists(lists, 3);
    printList(newHead); 
    return 0;
}