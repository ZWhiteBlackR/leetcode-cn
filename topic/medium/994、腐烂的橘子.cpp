#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xx[4] = {1,-1,0,0};
    int yy[4] = {0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>Queue;
        int row = grid.size(),col = grid[0].size(),cnt = 0;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1)
                    cnt++;
                else if(grid[i][j] == 2)
                    Queue.push(make_pair(i,j));
            }
        }
        int round = 0;
        while(!Queue.empty() && cnt > 0){
            round++;
            int len = Queue.size();
            for(int i = 0;i < len;i++){
                pair<int,int>temp = Queue.front();
                Queue.pop();
                int x = temp.first,y = temp.second;
                for(int i = 0;i < 4;i++){
                    int newx = x + xx[i],newy = y + yy[i];
                    if(newx >=0 && newx <row && newy >=0 && newy <col && grid[newx][newy] == 1){
                        grid[newx][newy] = 2;
                        cnt--;
                        Queue.push(make_pair(newx,newy));
                    }
                }
            }
        }
        return cnt > 0 ? -1 : round;
    }
};
int main(int argc,char* argv[]){

    return 0;
}