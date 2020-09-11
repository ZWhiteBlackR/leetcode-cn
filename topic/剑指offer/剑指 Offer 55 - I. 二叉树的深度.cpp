#include<bits/stdc++.h>
using namespace std;

/* 
 * 题目描述：
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含
 * 根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth,rightDepth) + 1;
    }
};