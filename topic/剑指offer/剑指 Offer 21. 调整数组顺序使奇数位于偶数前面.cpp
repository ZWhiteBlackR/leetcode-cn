#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数* 组的前半部分，所有偶数位于数组的后半部分。
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int start = 0,end = nums.size() - 1;
        while(start < end){
            while(start < end && nums[start] %2 == 1)
                start++;
            while(start < end && nums[end] % 2 == 0)
                end--;
            if(start < end){
                swap(nums[start],nums[end]);
            }
        }
        return  nums;
    }
};