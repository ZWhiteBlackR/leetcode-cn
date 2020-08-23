#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while(p != nullptr){
            length++;
            p = p->next;
        }
        for(int size = 1;size < length;size <<= 1){
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while(cur != nullptr){
                auto left = cur;
                auto right = cut(left,size);
                cur = cut(right,size);
                
                tail->next = merge(left,right);
                while(tail->next != nullptr){
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
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

    ListNode* merge(ListNode* l,ListNode* r){
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while(l != nullptr && r != nullptr){
            if(l->val < r->val){
                p->next = l;
                p = p->next;
                l = l->next;
            }else{
                p->next = r;
                p = p->next;
                r = r->next;
            }
        }
        p->next = (l == nullptr) ? r : l;
        return dummyHead.next;
    }
};
int main(int argc,char* argv[]){

    return 0;
}