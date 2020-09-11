#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 在字符串s中找出第一个只出现一次的字符。如果没有，返回一个单空* 格。 s只* * 包含小写字母。
 */
/*
 * 解题思路：
 * 用哈希表的思路记录每个字符出现的次数
 * 1. 注意字符为空的情况
 * 2. 可能有不存在的情况
 */  
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int>cnt(26,0);
        for(int i = 0;i < s.size();i++){
            cnt[s[i] - 'a']++;
        }
        for(int i = 0;i < s.size();i++){
            if(cnt[s[i] - 'a'] == 1)
                return s[i];
        }
        return ' ';
    }
};