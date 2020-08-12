#include<bits/stdc++.h>
using namespace std;
class SolutionOne {
public:
    //利用幂集性质
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        result.push_back(vector<int>{});
        for(int i = 0;i < nums.size();i++){
            int len = result.size();
            for(int j = 0;j < len;j++){
                vector<int>temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
class SolutionTwo {
public:
    vector<vector<int>>res;
    //回溯算法
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>track;
        backtrack(nums,0,track);
        return res;
    }
    void backtrack(vector<int>&nums,int start,vector<int>&track){
        res.push_back(track);
        for(int i = start;i < nums.size();i++){
            track.push_back(nums[i]);
            backtrack(nums,i + 1,track);
            track.pop_back();
        }
    }
};
class SolutionThree {
public:
    //递归算法
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0){
            return {{}};
        }
        int n = nums.back();
        nums.pop_back();
        vector<vector<int>>res = subsets(nums);
        int size = res.size();
        for(int i = 0;i < size;i++){
            vector<int>temp = res[i];
            temp.push_back(n);
            res.push_back(temp);
        }
        return res;
    }
};
int main(int argc,char* argv[]){

    return 0;
}