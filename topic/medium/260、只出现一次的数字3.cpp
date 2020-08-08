#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int num:nums){
            temp ^= num;
        }
        temp = temp & (-temp);
        vector<int>res(2,0);
        for(int num:nums){
            if(temp & num){
                res[0] ^= num;
            }else{
                res[1] ^= num;
            }
        }
        return res;
    }
};
int main(int argc,char* argv[]){

    return 0;
}