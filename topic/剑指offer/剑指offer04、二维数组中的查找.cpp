#include<bits/stdc++.h>
using namespace std;
/*
 * 因为数组中每一行和每一列都是有序的
 * 每次选择左上角的数组和target进行比较
 * 如果比target大就删除一列，如果比target小就删除一行
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int rows = matrix.size(),cols = matrix[0].size();
        bool found = false;
        int row = 0,col = cols - 1;
        while(row < rows && col >=0){
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                col--;
            else 
                row++;
        }
        return false;
    }
};