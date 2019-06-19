/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(k <= 1){
        return head;
    }
    // 保证链表长度 >=2
    if(NULL == head || NULL == head->next){
        return head;
    }
    struct ListNode *p = head;
    struct ListNode *preq = head;
    struct ListNode *q = preq->next;
    struct ListNode *postq = q->next;
    struct ListNode *nowFirst = head;
    struct ListNode *lastFirst = head;      // 记录上K个节点的首节点，转换后是尾节点
    struct ListNode *newHead = head;
    int count = 0;
    int setHead = 0;
    // 头结点置空
    while(1){
        lastFirst = nowFirst;
        nowFirst = p;
        // 将p移动k个节点
        while(NULL != p && count < k){
            // printf("p->val = %d\n", p->val);
            ++count;
            p = p->next;
        }
        // printf("count = %d\n", count);
        if(NULL == p && count != k){
            // 个数不足的节点保持原有顺序
            lastFirst->next = q;
            return newHead;
        }
        // 翻转p及其之前的节点
        while(q != p){
            postq = q->next;
            q->next = preq;
            preq = q;
            q = postq;
        }
        if(!setHead){
            newHead = preq;
            setHead = 1;
        }
        if(lastFirst != nowFirst){
            lastFirst->next = preq;
        }
        // 重置count开始下一轮循环
        count = 0;
    }
}

// 普通的链表翻转
struct ListNode *reverseList(struct ListNode *head){
    // 保证至少有两个节点
    if(NULL == head || NULL == head->next){
        return head;
    }
    struct ListNode *prep = head;
    struct ListNode *p = prep->next;
    struct ListNode *postp = p->next;
    while(NULL != p){
        postp = p->next;
        p->next = prep;
        prep = p;
        p = postp;
    }
    // 头结点置空
    head->next = NULL;
    return prep;
}
// 打印链表
void printList(struct ListNode *head){
    struct ListNode *p = head;
    while(NULL != p){
        printf("%d, ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char *argv[]){
    // struct ListNode ln5 = {5, NULL};
    // struct ListNode ln4 = {4, &ln5};
    struct ListNode ln4 = {4, NULL};
    struct ListNode ln3 = {3, &ln4};
    struct ListNode ln2 = {2, &ln3};
    struct ListNode ln1 = {1, &ln2};
    struct ListNode ln0 = {0, &ln1};
    printf("before\n");
    printList(&ln0);
    // struct ListNode *newHead = reverseList(&ln0);
    struct ListNode *newHead = reverseKGroup(&ln0, 3);
    printf("after\n");
    printList(newHead);
    return 0;
}