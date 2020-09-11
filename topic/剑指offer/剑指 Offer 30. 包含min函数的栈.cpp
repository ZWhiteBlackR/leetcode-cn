#include<bits/stdc++.h>
using namespace std;


/*
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该* 栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        while(!stackOne.empty())stackOne.pop();
        while(!stackTwo.empty())stackTwo.pop();
    }
    void push(int x) {
        stackOne.push(x);
        if(stackTwo.empty() || x <= stackTwo.top())
            stackTwo.push(x);
    }
    void pop() {
        if(!stackOne.empty()){
            int temp = stackOne.top();
            stackOne.pop();
            if(temp <= stackTwo.top())
                stackTwo.pop();
        }
    }
    int top() {
        return stackOne.top();
    }
    
    int min() {
        return stackTwo.top();
    }
private:
    stack<int>stackOne;
    stack<int>stackTwo;
};
