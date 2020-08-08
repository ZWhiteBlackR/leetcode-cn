#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalidrome(string s){
        string tmp = s;
        reverse(s.begin(),s.end());
        return s == tmp;
    }
    bool validPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1)
            return true;
        for(int i = 0;i < s.size();i++){
            if(s[i] == s[s.size() - 1 - i])
                continue;
            string leftStr = s.substr(i,s.size() - 2*i - 1);
            string rightStr = s.substr(i+1,s.size() - 2*i - 1);
            if(!isPalidrome(rightStr) && !isPalidrome(leftStr))
                return false;
            else 
                return true;
        }
        return true;
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    bool result = solution.validPalindrome("aydmda");
    cout << result << endl;
    return 0;
}