#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int index = 0;
        for(int i = 0;i < s.size();i++){
            if(isdigit(s[i]) || isalpha(s[i])){
               s[index++] = tolower(s[i]);
            }
        }
        for(int i = 0;i < index;i++){
            if(s[i] != s[index - 1 - i]){
                return false;
            }
        }
        return true;
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    bool result = solution.isPalindrome("A man, a plan, a canal: Panama");
    cout << result << endl;
    return 0;
}