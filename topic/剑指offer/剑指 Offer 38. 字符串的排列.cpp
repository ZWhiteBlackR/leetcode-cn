#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string>result;
        for(int i = 0;i < s.size();i++){
            if(!isexist(s,0,i)){
                swap(s[0],s[i]);
                int len = s.size() - 1;
                permutation(s,1,result);
                swap(s[0],s[i]);
            }
        }
        return result;
    }
    bool isexist(const string& s,int start,int end){
        for(int i = start;i < end;i++){
            if(s[i] == s[end])
                return true;
        }
        return false;
    }
    void permutation(string& s,int start,vector<string>&result){
        if(start == s.size()){
            result.push_back(s);
            return ;
        }
        for(int i = start;i < s.size();i++){
            if(!isexist(s,start,i)){
                swap(s[start],s[i]);
                permutation(s,start + 1,result);
                swap(s[start],s[i]);   
            }
        }
    }
};