#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxNumber = 0;
        vector<int>saleMoney(prices.size());
        for(int i = prices.size() - 1;i >=0;i--){
            saleMoney[i] = max(maxNumber,prices[i]);
            maxNumber = max(maxNumber,prices[i]);
        }
        int result = 0;
        for(int i = 0;i < prices.size();i++){
            result = max(result,saleMoney[i] - prices[i]);
        }
        return result;
    }
};