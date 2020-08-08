#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>dp(27,0);
        if(s.size() == 0){
            return -1;
        }
        for(int i = 0;i < s.size();i++){
            dp[s[i] - 'a']++;
        }
        for(int i = 0;i < s.size();i++){
            if(dp[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    int index = solution.firstUniqChar("leetcode");
    cout << index << endl;
}