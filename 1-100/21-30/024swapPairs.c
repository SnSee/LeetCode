/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next){
        return head;
    }
    struct ListNode *newHead;
    struct ListNode *p = head;
    struct ListNode *temp;
    if(head->next){
        newHead = head->next;
        head->next = newHead->next;
        newHead->next = head;
    }
    while(p->next){
        if(NULL == p->next->next){
            break;
        }
        temp = p->next;
        p->next = p->next->next;
        temp->next = p->next->next;
        p->next->next = temp;
        p = temp;
    }
    return newHead;
}
int main(int argc, const char *argv[]){
    return 0;
}