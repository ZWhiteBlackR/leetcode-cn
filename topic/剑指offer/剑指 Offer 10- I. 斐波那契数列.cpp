#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7; 
    int fib(int n) {
        int first = 0,second = 1;
        if(n == 0 || n == 1)return n;
        for(int i = 2;i <= n;i++){
           long long temp = (first + second) % mod;
           first = second;
           second = temp; 
        } 
        return second;
    }
};