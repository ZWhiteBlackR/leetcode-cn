#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return s;
        string result;
        int start = 0,end = s.size() - 1;
        while(start < s.size() && s[start] == ' ')start++;
        while(end >= 0 && s[end] == ' ')end--;
        for(int i = start;i <= end;i++){
            if(s[i] != ' ')
                result += s[i];
            else if(s[i - 1] != ' ')
                result += s[i];
        }
        reverse(result.begin(),result.end());
        start = 0,end = 0;
        for(int i = 0;i < result.size();i++){
            if(result[i] == ' '){
                reverse(result.begin() + start,result.begin() + i);
                start  = i + 1;
            }
        }
        reverse(result.begin() + start,result.end());
        return result;
    }  
};