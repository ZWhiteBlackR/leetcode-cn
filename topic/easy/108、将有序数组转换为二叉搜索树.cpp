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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end) {
        if(start > end)
            return nullptr;
        if(start == end)
            return new TreeNode(nums[start]);
        int medium = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[medium]);
        node->left = sortedArrayToBST(nums,start,medium - 1);
        node->right = sortedArrayToBST(nums,medium + 1,end);
        return node;
    }
};
int main(int argc,char* argv[]){


    return 0;
}