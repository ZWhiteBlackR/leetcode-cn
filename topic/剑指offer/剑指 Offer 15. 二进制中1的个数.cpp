#include<bits/stdc++.h>
using namespace std;

/*
 * 解题思路：
 * 方案一：不改变n，通过flag数进行左移,这样有多少个1就要循环多少次
 * 方案二：整数减去1和自身做与运算
 */
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag = 1;
        int cnt = 0;
        while(flag){
            if(flag & n)
                cnt++;
            flag <<= 1;
        }
        return cnt;
    }
};

class Solution2{
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            cnt++;
            n = (n - 1) & n;
        }
        return cnt;
    }
};