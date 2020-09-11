#include<bits/stdc++.h>
using namespace std;

/* 
 * 题目描述：
 * 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
 * B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 */

/*
 * 解题思路：
 * 对A树进行递归遍历，对于遇到的每个节点判断其是否和B的根节点相同
 * 如果节点和根节点的值相同的话，那么就去判断A树的左右子树是否包含B树的左右子* 树
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr)
            return false;
        bool result = false;
        if(A->val == B->val)
            result =  isHasSubStructure(A->left,B->left) && isHasSubStructure(A->right,B->right);
        if(!result)
            result = isSubStructure(A->left,B);
        if(!result)
            result = isSubStructure(A->right,B);
        return result;
    }
private:
    bool isHasSubStructure(TreeNode* A,TreeNode* B){
        if(B == nullptr)
            return true;
        else if(A == nullptr)
            return false;
        if(A->val != B->val)
            return false;
        return isHasSubStructure(A->left,B->left) && isHasSubStructure(A->right,B->right);
    }
};