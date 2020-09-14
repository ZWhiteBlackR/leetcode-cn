#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 10;
int dp[maxN][maxN];
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        for(int i = 0;i < text1.size();i++){
            for(int j = 0;j < text2.size();j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]) + 1;
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};