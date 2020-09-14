#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归实现
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root == nullptr)
            return result;
        preorderTraversal(root,result);
        return result;
    }
    void preorderTraversal(TreeNode* root,vector<int>&result){
        if(root == nullptr)
            return ;
        result.push_back(root->val);
        preorderTraversal(root->left,result);
        preorderTraversal(root->right,result);
    }
};

// 迭代实现
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root == nullptr)
            return result;
        preorderTraversal(root,result);
        return result;
    }
    void preorderTraversal(TreeNode* root,vector<int>&result){
        stack<TreeNode*>st;
        if(root != nullptr)st.push(root);
        while(!st.empty()){     
            TreeNode* node = st.top();
            if(node != nullptr){
                st.pop();
                if(node->right != nullptr)st.push(node->right);
                if(node->left != nullptr)st.push(node->left);
                st.push(node);
                st.push(nullptr);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
    }
};