#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * 方案一：遍历整个链表，由于后进先出，使用栈来实现
 * 方案二：因为递归本质就是一个栈，所以可以使用递归实现
*/
class Solution1 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int>result;
        stack<int>value;
        while(head != nullptr){
            value.push(head->val);
            head = head->next;
        }
        while(!value.empty()){
            result.push_back(value.top());
            value.pop();
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int>result;
        reversePrint(head,result);
        return result;
    }
    void reversePrint(ListNode* head,vector<int>& result){
        if(head == nullptr)
            return ;
        reversePrint(head->next,result);
        result.push_back(head->val);
        return ;
    }
};