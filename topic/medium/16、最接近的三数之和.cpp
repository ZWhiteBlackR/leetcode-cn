#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0;i < nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int l = i + 1,r = nums.size() - 1;
            while(l < r){
                int temp = nums[i] + nums[l] + nums[r];
                if(temp == target)
                    return target;
                else if(temp < target){
                    if(abs(temp-target) < abs(result-target)){
                        result = temp;
                    }
                    l++;
                }else{
                    if(abs(temp-target) < abs(result-target)){
                        result = temp;
                    }
                    r--;
                }
            }
        }
        return result;
    }
};

int main(int argc,char* argv[]){


    return 0;
}