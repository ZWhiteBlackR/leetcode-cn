#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res;
        res.push_back(0);
        for(int i = 0 ;i < n;i++){
            vector<int>temp = res;
            reverse(temp.begin(),temp.end());
            for(int j = 0;j < temp.size();j++){
                res.push_back(temp[j] + (1 << i));
            }
        }
        return res;
    }
};

int main(int argc,char* argv[]){


    return 0;
}