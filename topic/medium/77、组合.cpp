#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 回溯法
    vector<vector<int>>res;
    vector<vector<int>> combine(int n, int k) {
        vector<int>track;
        backtrack(1,n,k,0,track);
        return res;
    }
    void backtrack(int start,int n,int k,int cnt,vector<int>&track){
        if(cnt ==  k){
            res.push_back(track);
            return ;
        }
        for(int i = start;i <= n;i++){
            track.push_back(i);
            backtrack(i + 1,n,k,cnt+1,track);
            track.pop_back();   
        }
    }
};
int main(int argc,char* argv[]){


    return 0;
}