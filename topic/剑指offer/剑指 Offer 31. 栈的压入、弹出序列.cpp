#include<bits/stdc++.h>
using namespace std;


/*
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的* 弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压* 栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,* 2} 就不可能是该压栈序列的弹出序列。
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())
            return false;
        stack<int>st;
        int index = 0;
        for(int i = 0;i < popped.size();i++){
            while((st.empty() || st.top() != popped[i]) && index < pushed.size()){
                st.push(pushed[index++]);
            }
            if(st.top() != popped[i])
                break;
            st.pop();
        }
        return st.empty();
    }
};