#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode dummyHead(0);
        dummyHead.next = head;
        int length = 0;
        auto p = head,tail = head;
        while(p != nullptr){
            tail = p;
            length++;
            p = p->next;
        }
        k %= length;
        k = length - k;
        head = cut(head,k);
        if(head == nullptr)
            return dummyHead.next;
        tail->next = dummyHead.next;
        return head;
    }


    ListNode* cut(ListNode* head,int n){
        auto p = head;
        while(--n && p != nullptr){
            p = p->next;
        }
        if(p == nullptr)
            return nullptr;
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
};


int main(int argc,char* argv[]){


    return 0;
}