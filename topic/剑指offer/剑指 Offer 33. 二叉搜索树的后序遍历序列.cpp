#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 * true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0 || postorder.size() == 1)
            return true;
        return verifyPostorder(postorder,0,postorder.size() - 1);
    }
    bool verifyPostorder(vector<int>& postorder,int start,int end){
        if(start >= end)
            return true;
        int index = 0;
        for(index = start;index < end;index++){
            if(postorder[index] > postorder[end]){
                break;
            }
        }
        for(int j = index;j < end;j++){
            if(postorder[j] < postorder[end])
                return false;
        }
        return verifyPostorder(postorder,start,index - 1) && verifyPostorder(postorder,index,end - 1);
    }
};



