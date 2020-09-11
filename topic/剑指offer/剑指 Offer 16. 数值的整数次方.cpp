#include<bits/stdc++.h>
using namespace std;


/*
 * 题目描述：
 * 实现函数double Power(double base, int exponent)，求base的exponent次* 方。不得使用库函数，同时不需要考虑大数问题。
 */

/*
 * 解题思路：
 * 幂值是一个有符号整数，应该考虑正数，零和负数的情况
 * 同时也应该考虑底数的情况
 */
class Solution {
public:
    bool isInvalidInput = true;
    double myPow(double x, long long n) {
        if(n == 0)
            return 1;
        if(equal(x,0) && n < 0){
            isInvalidInput = true;
            return 0;
        }
        double result = quickPow(x,abs(n));
        if(n < 0)
            result = 1.0 / result;
        return result;
    }
    bool equal(double lhs,double rhs){
        if(abs(lhs - rhs) < 0.000000001)
            return true;
        return false;
    }
    double quickPow(double x,long long n){
        double result = 1;
        while(n > 0){
            if(n & 1)result = result * x;
            x *= x;
            n >>= 1;
        }
        return result;
    }
};