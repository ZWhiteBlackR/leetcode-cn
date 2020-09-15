#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int start = 0,end = nums.size() - 1;
        while(start <= end){
            int middle = (start + end) / 2;
            if(nums[middle] == target){
                return middle;
            }else if(nums[middle] >= nums[start]){
                if(nums[middle] > target && target >= nums[start])
                    end = middle - 1;
                else
                    start = middle + 1;
            }else{
                if(target > nums[middle] && target <= nums[end])
                    start = middle + 1;
                else
                    end = middle - 1;
            }
        }
        return -1;
    }
};