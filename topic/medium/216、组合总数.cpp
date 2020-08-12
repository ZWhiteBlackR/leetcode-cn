#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>track;
        backtrack(1,k,n,0,0,track);
        return res;
    }
    void backtrack(int start,int k,int n,int cnt,int sum,vector<int>&track){
        if(cnt == k && sum == n){
            res.push_back(track);
            return ;
        }
        if(sum > n)
            return ;
        for(int i = start;i <= 9;i++){
            track.push_back(i);
            backtrack(i + 1,k,n,cnt + 1,sum + i,track);
            track.pop_back();
        }
    }
};
int main(int argc,char* argv[]){


    return 0;
}