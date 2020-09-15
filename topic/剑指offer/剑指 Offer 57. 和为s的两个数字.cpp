#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是× * s。如果有多对数字的和等于s，则输出任意一对即可。
 */

/*
 * 解题思路：
 * 因为数组是递增的，所以可以使用滑动窗口来解决这道题
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1;
        vector<int>result;
        while(start < end){
            if(nums[start] + nums[end] == target){
                result.push_back(nums[start]);
                result.push_back(nums[end]);
                return result;
            }else if(nums[start] + nums[end] < target){
                start++;
            }else{
                end--;
            }
        }
        return result;
    }
};