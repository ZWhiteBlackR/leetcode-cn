#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int u = 0,d = n - 1,l = 0,r = n - 1;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int cnt = 1;
        while (true){
            for(int i = l;i <= r;i++)matrix[u][i] = cnt++;
            if(++u > d)break;
            for(int i = u;i <= d;i++)matrix[i][r] = cnt++;
            if(--r < l)break;
            for(int i = r;i >= l;i--)matrix[d][i] = cnt++;
            if(--d < u)break;
            for(int i = d;i >= u;i--)matrix[i][l] = cnt++;
            if(++l > r)break;
        }
        return matrix;
    }
};

int main(int argc,char* argv[]){


    return 0;
}