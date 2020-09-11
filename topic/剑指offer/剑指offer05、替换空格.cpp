#include<bits/stdc++.h>
using namespace std;
/* 第一种方案使用单独的string来存储结果，但需要额外的空间
 * 第二种方案先遍历一遍获得空格的个数，提前分配空间
*/
class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' ')
                cnt++;
        }
        int len = s.size();
        s.resize(len + cnt * 2);
        int index = s.size() - 1;
        for(int i = len - 1;i >= 0;i--){
            if(s[i] != ' '){
                s[index--] = s[i];
            }else{
                s[index--] = '0';
                s[index--] = '2';
                s[index--] = '%';
            }
        }
        return s;
    }
};