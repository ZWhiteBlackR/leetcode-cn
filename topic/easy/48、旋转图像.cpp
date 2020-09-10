#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int start = 0,end = matrix.size()-1;start < end;start++,end--){
            for(int s = start,e = end;s < end;s++,e--){
                int temp = matrix[start][s];
                matrix[start][s] = matrix[e][start];
                matrix[e][start] = matrix[end][e];
                matrix[end][e] = matrix[s][end];
                matrix[s][end] = temp;
            }
        }
    }
}; 
int main(int argc,char* argv[]){

    return 0;
}