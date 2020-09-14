#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    const int mod  = 1e9 + 7;
    int numWays(int n) {
        if(n == 0 || n == 1)
            return 1;
        int pre = 1,current = 1;
        for(int i = 2;i <= n;i++){
            long long value = pre + current;
            value %= mod;
            pre = current;
            current = value;
        }
        return current;
    }
};