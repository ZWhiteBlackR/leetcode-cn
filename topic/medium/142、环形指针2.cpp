#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)return nullptr;
        ListNode* slow = head,*fast = head;
        bool iscycle = false;
        while(fast->next !=nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle)return nullptr;
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(int argc,char* argv[]){


    return 0;
}