#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * 题目描述：
 * 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开* 始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开* 始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
 */

/*
 * 解题思路：
 * 1. 考虑链表为空的情况
 * 2. 考虑k值为0的情况
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr || k == 0)
            return nullptr;
        ListNode* node = head;
        for(int i = 0;i < k - 1;i++){
            if(node->next != nullptr)
                node = node->next;
            else return nullptr;
        }
        ListNode* behind = head;
        while(node->next != nullptr){
            node = node->next;
            behind = behind->next;
        }
        return behind;
    }
};