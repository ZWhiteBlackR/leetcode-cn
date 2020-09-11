#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        vector<int>result;
        if(root == nullptr)
            return result;
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
            if(temp->left != nullptr)
                que.push(temp->left);
            if(temp->right != nullptr)
                que.push(temp->right);
        }
        return result;
    }
};