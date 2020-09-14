#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
 * 返回仅包含 1 的最长（连续）子数组的长度。
 */
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0,right = 0,cnt = 0,result = 0;
        while(right < A.size()){
            if(A[right] == 0)
                cnt++;
            if(cnt > K){
                if(A[left] == 0)cnt--;
                left++;
            }
            result = max(result,right - left + 1);
            right++;
        }
        return result;
    }
};