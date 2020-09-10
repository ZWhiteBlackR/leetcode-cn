#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 递归实现
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head ==  nullptr || head->next == nullptr)
            return head;

        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
};

// 迭代实现
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        if(head == nullptr)
            return head;
        while(head != nullptr){
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};

int main(int argc,char* argv[]){

    return 0;
}