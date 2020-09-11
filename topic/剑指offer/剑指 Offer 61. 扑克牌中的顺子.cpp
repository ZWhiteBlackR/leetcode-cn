#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int cnt = 0,gap = 0;
        for(int i = 0;i < nums.size();i++){
            if((i != 0) && (nums[i] == nums[i-1]) && (nums[i] != 0))
                return false;
            if(nums[i] == 0)
                cnt++;
            if((i != 0) && nums[i - 1] != 0)
                gap += nums[i] - nums[i-1] - 1;
        }
        return cnt >= gap;
    }
};