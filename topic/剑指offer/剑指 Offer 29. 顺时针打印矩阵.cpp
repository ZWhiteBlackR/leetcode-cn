#include<bits/stdc++.h>
using namespace std;


/*
 * 题目描述：
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        if(matrix.size() == 0)
            return result;
        int left = 0,right = matrix[0].size() - 1;
        int up = 0,down = matrix.size() - 1;
        while(true){
            for(int i = left;i <= right;i++)
                result.push_back(matrix[up][i]);
            if(++up > down)break;
            for(int i = up;i <= down;i++)
                result.push_back(matrix[i][right]);
            if(--right < left)break;
            for(int i = right;i >= left;i--)
                result.push_back(matrix[down][i]);
            if(--down < up)break;
            for(int i = down;i >= up;i--)
                result.push_back(matrix[i][left]);
            if(++left > right)break;
        }
        return result;
    }
};
