/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

// 思路1：记录所有节点的指针
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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n){
    int pSize = 100;
    int listSize = 0;
    // 存储每个节点的指针
    struct ListNode **pNode = (struct ListNode **)malloc(sizeof(struct ListNode *) * pSize);
    struct ListNode *p = head;
    while(NULL != p){
        ++listSize;
        if(listSize > pSize){
            pSize += 100;
            pNode = (struct ListNode **)realloc(pNode, sizeof(struct ListNode *) * pSize);
        }
        pNode[listSize-1] = p;
        p = p->next;
    }
    if(0 == listSize - n){
        // 被删除的是头节点
        // 需要释放空间吗？
        head = head->next;
    }
    else if(1 == n){
        // 被删除的是最后一个节点
        (pNode[listSize-2])->next = NULL;
    }
    else{
        (pNode[listSize-n-1])->next = pNode[listSize-n+1];
    }

    if(NULL != pNode){
        free(pNode);
        pNode = NULL;
    }
    return head;
}

int main(int argc, const char *argv[]){

    return 0;
}