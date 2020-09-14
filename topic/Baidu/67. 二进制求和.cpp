#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.size() < b.size())
            swap(a,b);
        int lenA = a.size(),lenB = b.size();
        int over = 0;
        for(int i = 0;i < lenB;i++){
            int temp = (a[i] - '0') + (b[i] - '0') + over;
            a[i] = (temp % 2) + '0';
            over = temp / 2;
        }
        for(int i = lenB;i < lenA;i++){
            int temp = a[i] - '0' + over;
            a[i] = (temp % 2) + '0';
            over = temp / 2;
        }
        while(over != 0){
            a += (over % 2) + '0';
            over /= 2;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};