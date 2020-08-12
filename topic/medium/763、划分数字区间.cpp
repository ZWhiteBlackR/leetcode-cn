#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>dp(26,0);
        for(int i = 0;i < S.size();i++){
            dp[S[i] - 'a'] = i;
        }
        int maxIndex = -1;
        vector<int>result;
        string temp;
        for(int i = 0;i < S.size();i++){
            temp += S[i];
            maxIndex = max(maxIndex,dp[S[i] - 'a']);
            if(i == maxIndex){
                result.push_back(temp.size());
                temp.clear();
                maxIndex = -1;
                continue;
            }
        }
        return result;
    }
};
int main(int argc,char* argv[]){

    return 0;
}