#include<bits/stdc++.h>
using namespace std;


/*
 * 题目描述：
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆* 序对。输入一个数组，求出这个数组中的逆序对的总数。
 */
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int>copy(nums.size());
        return reversePairs(nums,copy,0,nums.size() - 1);
    }
    int reversePairs(vector<int>& nums,vector<int>& copy,int start,int end){
        if(start >= end)
            return 0;
        int middle = (start + end) / 2;
        int left = reversePairs(nums,copy,start,middle);
        int right = reversePairs(nums,copy,middle + 1,end);
        int cnt = 0,index = end;
        int i = middle,j = end;
        while(i >= start && j > middle){
            if(nums[i] > nums[j]){
                copy[index--] = nums[i--];
                cnt += j - middle;
            }else{
                copy[index--] = nums[j--];
            }
        }
        while(i >= start)
            copy[index--] = nums[i--];
        while(j > middle)
            copy[index--] = nums[j--];
        index = start;
        while(index <= end){
            nums[index] = copy[index];
            index++;
        }
        return left + right + cnt;
    }
};