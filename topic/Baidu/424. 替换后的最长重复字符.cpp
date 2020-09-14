#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>dp(26,0);

        int left = 0,right = 0,result = 0,maxCnt = 0;
        while(right < s.size()){ 
            dp[s[right] - 'A']++;
            maxCnt = max(maxCnt,dp[s[right] - 'A']);
            if(right - left + 1 > maxCnt + k){
                dp[s[left] - 'A']--;
                left++;
            }
            result = max(result,right - left + 1);
            right++;
        }
        return result; 
    }
};