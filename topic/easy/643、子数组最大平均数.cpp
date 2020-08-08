#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0;
        for(int i = 0;i < k;i++){
            maxSum += nums[i];
        }
        int temp = maxSum;
        for(int i = k;i < nums.size();i++){
            temp = temp - nums[i - k] + nums[i];
            maxSum = max(maxSum,temp);
        }
        return double(maxSum) / k;
    }
};
int main(int argc,char* argv[]){


    return 0;
}