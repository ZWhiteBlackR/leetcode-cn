#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>>group;
        for(int i = 0;i < groupSizes.size();i++){
            group.push_back(make_pair(groupSizes[i],i));
        }
        vector<vector<int>>result;
        sort(group.begin(),group.end());
        for(int i = 0;i < group.size();i++){
            vector<int>temp;
            for(int j = i;j < i + group[i].first;j++){
                temp.push_back(group[j].second);
            }
            result.push_back(temp);
            temp.clear();
            i = i + group[i].first - 1;
        }
        return result;
    }
};
int main(int argc,char* argv[]){
    return 0;
}