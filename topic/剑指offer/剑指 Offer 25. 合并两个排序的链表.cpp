#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 题目描述：
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr)
            return l1 == nullptr ? l2 : l1;
        ListNode dummyNode(0);
        ListNode* head = &dummyNode;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }else{
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        head->next = (l1 == nullptr) ? l2 : l1;
        return dummyNode.next;
    }
};