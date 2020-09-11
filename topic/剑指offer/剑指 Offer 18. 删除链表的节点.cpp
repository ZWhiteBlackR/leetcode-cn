#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * 题目描述：
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 */

/*
 * 解题思路：
 * 1. 在链表的操作当中不要直接使用头指针，构造一个头结点出来使用
 * 2. 使用循环来迭代链表时不要忘记更新当前节点的位置
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode* pre = &dummyNode;
        while(head != nullptr){
            if(head->val == val){
                pre->next = head->next;
                head->next = nullptr;
                break;
            }
            pre = head;
            head = head->next;
        }
        return dummyNode.next;
    }
};
