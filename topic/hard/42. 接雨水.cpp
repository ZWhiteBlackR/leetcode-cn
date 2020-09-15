#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨* 之后能接多少雨水。
 */

/*
 * 解题思路：
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int result = 0;
        for(int i = 0;i < height.size();i++){
            while(!st.empty()&&height[st.top()] <= height[i]){
                int temp = height[st.top()];
                st.pop();
                if(st.empty())break;
                int minHeight = min(height[i],height[st.top()]);
                int distance = i - st.top() - 1;
                result += distance * (minHeight - temp);
            }
            st.push(i);
        }
        return result;
    }
};