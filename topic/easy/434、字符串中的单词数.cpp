#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)
            return 0;
        int cnt = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' ' && i > 0 && s[i-1] != ' '){
                cnt++;
            }
        }
        if(s[s.size() - 1] != ' ')
            cnt++;
        return cnt;
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    int cnt = solution.countSegments("Hello, my name is John");
    cout << cnt << endl;
    return 0;
}