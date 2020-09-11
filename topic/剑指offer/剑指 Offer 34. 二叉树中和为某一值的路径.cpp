#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>result;
        if(root == nullptr)
            return result;
        int tempSum = 0;
        vector<int>path;
        pathSum(root,tempSum,sum,path,result);
        return result;
    }
    void pathSum(TreeNode* root, int tempSum,int sum,vector<int>&path,vector<vector<int>>&result){
        if(root == nullptr)
            return ;
        tempSum += root->val;
        path.push_back(root->val);
        if(root->right == nullptr && root->left == nullptr && tempSum == sum){
            result.push_back(path);
            tempSum -= root->val;
            path.pop_back();
            return ;
        }
        pathSum(root->left,tempSum,sum,path,result);
        pathSum(root->right,tempSum,sum,path,result);
        tempSum -= root->val;
        path.pop_back();
        return ;
    }
};