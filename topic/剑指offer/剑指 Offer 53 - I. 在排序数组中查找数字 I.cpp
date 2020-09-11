#include<bits/stdc++.h>
using namespace std;
/*
 * 题目描述：
 * 统计一个数字在排序数组中出现的次数。
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first_index = first_bound(nums,target);
        int last_index = last_bound(nums,target);
        if(first_index == -1 || last_index == -1)
            return 0;
        return last_index - first_index + 1;
    }
    int first_bound(vector<int>& nums,int target){
        if(nums.size() == 0)
            return -1;
        int start = 0,end = nums.size() - 1;
        while(start < end){
            int middle = (start + end) / 2;
            if(target == nums[middle]){
                if(middle == 0 || nums[middle - 1] < target)
                    return middle;
                end = middle - 1;
            }else if(nums[middle] > target){
                end = middle - 1;
            }else{
                start = middle + 1;
            }
        }
        return nums[start] == target ? start : -1; 
    }
    int last_bound(vector<int>& nums,int target){
        if(nums.size() == 0)
            return -1;
        int start = 0,end = nums.size() - 1;
        while(start < end){
            int middle = (start + end) / 2;
            if(target == nums[middle]){
                if(middle == nums.size() - 1 || nums[middle + 1] > target)
                    return middle;
                start = middle + 1;
            }else if(nums[middle] > target){
                end = middle - 1;
            }else{
                start = middle + 1;
            }
        }
        return nums[start] == target ? start : -1; 
    }
};