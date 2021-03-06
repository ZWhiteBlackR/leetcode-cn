#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 1)
            return "";
        int maxlen = 0;
        int start = 0,end = 0;
        for(int i = 0;i < s.size();i++){
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            int len = max(len1,len2);
            if(len > end - start + 1){
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start,end - start + 1);
    }
    int expandAroundCenter(string s,int left,int right){
        while(left >= 0 && right < s.length() && s[left] == s[right])
            left--,right++;
        return right - left - 1;
    }
};
int main(int argc,char* argv[]){

    return 0;
}