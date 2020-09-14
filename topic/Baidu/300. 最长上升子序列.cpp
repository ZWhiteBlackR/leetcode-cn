#include<bits/stdc++.h>
using namespace std;


/*
 * 题目描述：
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 */

/* 
 * 时间复杂度为O(n^2)实现
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int>dp(nums.size() + 1,1);
        int result = 0;
        for(int i = 0;i < nums.size();i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            result = max(result,dp[i]);
        }
        return result;
    }
};

/*
 * 时间复杂度为O(nlogn)实现
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<long long>dp(nums.size(),LONG_LONG_MAX);
        for(int i = 0;i < nums.size();i++){
            *lower_bound(dp.begin(),dp.end(),nums[i]) = nums[i];
        }
        return lower_bound(dp.begin(),dp.end(),LONG_LONG_MAX)-dp.begin();
    }
};