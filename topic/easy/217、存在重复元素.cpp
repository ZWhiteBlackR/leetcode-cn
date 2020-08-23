#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(int num:nums){
            if(mp[num] == true)
                return true;
            mp[num] = true;
        }
        return false;
    }
};

int main(int argc,char* argv[]){


    return 0;
}