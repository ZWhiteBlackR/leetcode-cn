#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        int len = 0;
        auto current = &dummyHead;
        while(len < m - 1){
            len++;
            current = current->next;
        }
        auto left = current->next;
        len++;
        ListNode* pre = nullptr;
        while(len <= n){
            auto right = left->next;
            len++;
            left->next = pre;
            pre = left;
            left = right;
        }
        current->next->next = left;
        current->next = pre;
        return dummyHead.next;
    }
};

int main(int argc,char* argv[]){


    return 0;
}