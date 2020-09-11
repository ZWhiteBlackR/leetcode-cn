#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = nums[0],currentValue = nums[0];
        for(int i = 1;i < nums.size();i++){
            currentValue = max(currentValue + nums[i],nums[i]);
            maxValue = max(maxValue,currentValue);
        }
        return maxValue;
    }
};