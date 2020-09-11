#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0)
            return vector<int>();
        int start = 0,end = arr.size() - 1;
        int index = partition(arr,start,end);
        while(index != (k - 1)){
            if(index < (k - 1)){
                start = index + 1;
                index = partition(arr,start,end);
            }else{
                end = index - 1;
                index = partition(arr,start,end);
            }
        }
        vector<int>result;
        for(int i = 0;i < k;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
    int partition(vector<int>& arr,int start,int end){
        int index = (start + end) / 2;
        swap(arr[index],arr[end]);
        index = start;
        for(int i = start;i < end;i++){
            if(arr[i] < arr[end]){
                swap(arr[i],arr[index++]);
            }
        }
        swap(arr[index],arr[end]);
        return index;
    }
};