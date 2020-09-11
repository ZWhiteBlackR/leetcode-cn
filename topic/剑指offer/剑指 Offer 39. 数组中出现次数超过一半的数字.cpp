#include<bits/stdc++.h>
using namespace std;


class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int start = 0,end = nums.size() - 1;
        int middle = nums.size() / 2;
        int index = partition(nums,0,nums.size() - 1);
        while(index != middle){
            if(index < middle){
                start = index + 1;
                index = partition(nums,start,end);
            }else{
                end = index - 1;
                index = partition(nums,start,end);
            }
        }
        return nums[middle];
    }
    int partition(vector<int>& nums,int start,int end){
        int index = (start + end) / 2;
        swap(nums[index],nums[end]);
        index = start;
        for(int i = start;i < end;i++){
            if(nums[i] < nums[end]){
                swap(nums[i],nums[index++]);
            }
        }
        swap(nums[index],nums[end]);
        return index;
    }
};


class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int value = nums[0],cnt = 0;
        for(int i = 0;i < nums.size();i++){
            if(cnt == 0){
                value = nums[i];
                cnt = 1;
            }
            else if(value == nums[i])
                cnt++;
            else
                cnt--;
        }
        return value;
    }
};