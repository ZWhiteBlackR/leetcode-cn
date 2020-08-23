#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return s;
        int start = 0,end = 0;
        int len = s.size();
        for(int i = 0;i < len;i++){
            if(i > 0 && s[i] == ' ' && s[i-1] != ' '){
                reverse(s.begin() + start,s.begin() + end);
                start = end = i + 1;
                continue;
            }
            end++;
        }
        if(s[len - 1] != ' ')
            reverse(s.begin() + start,s.begin() + end);
        return s;
    }
};

int main(int argc,char* argv[]){


    return 0;
}