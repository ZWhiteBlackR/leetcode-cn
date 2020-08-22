#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>results;
        if(nums.size() < 3)
            return results;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0)
                return results;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1,r = nums.size() - 1;
            while(l < r){
                int temp = nums[i] + nums[l] + nums[r];
                if(temp == 0){
                    results.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l+1])
                        l++;
                    while(l < r && nums[r] == nums[r-1])
                        r--;
                    l++,r--;
                }
                else if(temp > 0)
                    r--;
                else l++;
            }
        }
        return results;
    }
};
int main(int argc,char* argv[]){


    return 0;
}