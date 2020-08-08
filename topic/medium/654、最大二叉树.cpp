#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums,int start,int end) {
        if(start > end){
            return nullptr;
        }else if(start == end){
            return new TreeNode(nums[start]);
        }
        auto it = max_element(nums.begin() + start,nums.begin() + end + 1);
        TreeNode* node = new TreeNode(*it);
        node->right = constructMaximumBinaryTree(nums,it - nums.begin() + 1,end);
        node->left = constructMaximumBinaryTree(nums,start,it - nums.begin() - 1);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        else if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }
        return constructMaximumBinaryTree(nums,0,nums.size() - 1);
    }
};