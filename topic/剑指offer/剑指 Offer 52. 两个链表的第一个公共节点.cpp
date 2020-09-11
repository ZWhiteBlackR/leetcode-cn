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
        int ALength = 0,BLength = 0;
        ListNode* node = headA;
        while(node != nullptr){
            ALength++;
            node = node->next;
        }        
        node = headB;
        while(node != nullptr){
            BLength++;
            node = node->next;
        }
        if(ALength > BLength){
            int diff = ALength - BLength;
            while(diff--){
                headA = headA->next;
            }
        }else{
            int diff = BLength - ALength;
            while(diff--){
                headB = headB->next;
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