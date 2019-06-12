/*
思路2：用两个指针，第一个指针先走n个节点，然后两个指针一起走，直到第一个指针到达末尾，
删除第二个指针指向的节点即可
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n){
    struct ListNode headNode;
    headNode.next = head;
    struct ListNode *p1 = &headNode;
    struct ListNode *p2 = &headNode;
    // p1 先走 n 步, 由于n在有效范围内，不检查
    while(n > 0){
        p1 = p1->next;
        --n;
    }
    // p1, p2 一起走，直到 p1 到达末尾
    while(NULL != p1->next){
        p1 = p1->next;
        p2 = p2->next;
    }
    // 删除 p2 指向的节点的下一个节点
    p2->next = p2->next->next;
    return headNode.next;
}
int main(int argc, const char *argv[]){
    return 0;
}