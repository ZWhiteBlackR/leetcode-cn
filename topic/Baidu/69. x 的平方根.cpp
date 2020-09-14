#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int mySqrt(int x) {
        long long start = 0,end = x;
        while(start < end){
            long long middle = (start + end + 1) / 2;
            long long temp = middle * middle;
            if(temp == x)
                return middle;
            else if(temp > x){
                end = middle - 1;
            }else{
                start = middle;
            }
        }
        return (int)start;
    }
};