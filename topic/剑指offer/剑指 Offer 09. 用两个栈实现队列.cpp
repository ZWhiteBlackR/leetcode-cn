#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和     * deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中* 没有元素，deleteHead 操作返回 -1 )
*/

/*
 * 解题思路：
 * 进队列将元素直接放到第一个栈中
 * 出队列先判断第二个队列是否为空，如果为空的话将第一个队列中的元素出栈插入到
 * 第二个队列中
*/
class CQueue {
public:
    CQueue() {
        while(!stackOne.empty())stackOne.pop();
        while(!stackTwo.empty())stackTwo.pop();
    }
    
    void appendTail(int value) {
        stackOne.push(value);
    }
    
    int deleteHead() {
        if(stackTwo.empty()){
            while(!stackOne.empty()){
                stackTwo.push(stackOne.top());
                stackOne.pop();
            }
        }
        // 获取一个栈中元素的时候需要判断其是否为空
        if(stackTwo.empty())
            return -1;
        int value = stackTwo.top();
        stackTwo.pop();
        return value;
    }
private:
    stack<int>stackOne;
    stack<int>stackTwo;
};