#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两
 * 个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 */
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.size() == 2)
            return nums;
        vector<int>result;
        int xorResult = 0;
        for(int i = 0;i < nums.size();i++){
            xorResult ^= nums[i];
        }
        int mask = 1;
        while((xorResult & mask) == 0){
            mask <<= 1;
        }
        int arrayOne = 0,arrayTwo = 0;
        for(int i = 0;i < nums.size();i++){
            if((nums[i] & mask) == 0){
                arrayOne ^= nums[i];
            }else{
                arrayTwo ^= nums[i];
            }
        }
        result.push_back(arrayTwo);
        result.push_back(arrayOne);
        return result;
    }
};