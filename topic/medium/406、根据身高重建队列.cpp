#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& lhs,vector<int>& rhs){
        if(lhs[0] != rhs[0])
            return lhs[0] > rhs[0];
        return lhs[1] < rhs[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.size() <= 1){
            return people;
        }
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>new_people;
        for(int i = 0;i < people.size();i++){
            new_people.insert(new_people.begin() + people[i][1],people[i]);
        }
        return new_people;
    }
};

int main(int argc,char* argv[]){
    
}