#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* node = headA;
        int ALength = 0,BLength = 0;
        while(node != nullptr){
            node = node->next;
            ALength++;
        }
        node = headB;
        while(node != nullptr){
            node = node->next;
            BLength++;
        }
        if(ALength < BLength){
            int diff = BLength - ALength;
            while(diff--){
                headB = headB->next;
            }
        }
        if(ALength > BLength){
            int diff = ALength - BLength;
            while(diff--){
                headA = headA->next;
            }
        }
        while(headA != nullptr){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};