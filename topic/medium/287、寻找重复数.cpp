#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0,fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int pre1 = 0,pre2 = slow;
        while(pre1 != pre2){
            pre1 = nums[pre1];
            pre2 = nums[pre2];
        }
        return pre2;
    }
};
int main(int argc,char* argv[]){


    return 0;
}