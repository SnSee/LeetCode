/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

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
int main(){
    return 0;
}