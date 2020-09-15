#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两* 个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 */

/*
 * 解题思路：
 * 使用尺取法来进行遍历
 */
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>result;
        list<int>lt;
        int start = 1,end = 1,sum = 0;
        while(1){
            while(end <= target/2 + 1 && sum < target){
                lt.push_back(end);
                sum += end;
                end++;
            }
            if(sum < target)
                break;
            if(sum == target){
                vector<int>temp;
                for(auto it = lt.begin();it != lt.end();it++){
                    temp.push_back(*it);
                }
                result.push_back(temp);
            }
            sum -= start;
            lt.pop_front();
            start++;
        }
        return result;
    }
};