#include<bits/stdc++.h>
using namespace std;
/*
 * 题目描述：
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增* 排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,* 2,3,4,5] 的一个旋转，该数组的最小值为1
 */

/*
 * 解题思路：
 * 进行二分查找
 * 1. 考虑该数组本身就是单调递增的情况（将首部0个元素搬到尾部）
 * 2. 数组当中有重复元素（array[mid] == array[start] == array[end]）
 */
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int start = 0,end = numbers.size() - 1;
        while(start < end){
            int mid = (start + end) / 2;
            if(numbers[mid] > numbers[end])
                start = mid + 1;
            else if(numbers[mid] < numbers[end])
                end = mid;
            else 
                end -- ;
        }
        return numbers[start];
    }
};