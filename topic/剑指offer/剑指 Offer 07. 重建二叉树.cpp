#include<bits/stdc++.h>
using namespace std;

/* 题目描述
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
 * 假设输入的前序遍历和中 序遍历的结果中都不含重复的数字。
*/

/*
 * 解题思路
 * 根据前序遍历的第一个节点，将中序遍历分为左子树和右子树
 * 然后不断的递归
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0)
            return nullptr;
        return buildTree(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend){
        if(prestart > preend || instart > inend)
            return nullptr;
        int value = preorder[prestart];
        int index = instart;
        for(int i = instart;i <= inend;i++){
            if(inorder[i] == value){
                index = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(value);
        int len = index - instart;
        node->left = buildTree(preorder,prestart + 1,prestart + len,inorder,instart,index - 1);
        node->right = buildTree(preorder,prestart + len + 1,preend,inorder,index + 1,inend);
        return node;
    }
};
