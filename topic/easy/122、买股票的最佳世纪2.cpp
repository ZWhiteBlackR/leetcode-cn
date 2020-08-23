#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        int result = 0;
        for(int i = 1;i < prices.size();i++){
            int temp = prices[i] - prices[i-1];
            if(temp > 0)result += temp;
        }
        return result;
    }
};
int main(int argc,char* argv[]){


    return 0;
}





