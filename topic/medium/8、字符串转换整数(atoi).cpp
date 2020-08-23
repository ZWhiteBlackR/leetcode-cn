#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        bool isNegativeNumber = false;
        int i = 0;
        while(i < str.size() && str[i] == ' ')
            i++;
        if(i == str.size() || (str[i] != '+' && str[i] != '-' && !isdigit(str[i])))
            return 0;
        isNegativeNumber = (str[i] == '-');
        i = (str[i] == '+' || str[i] == '-') ? i + 1 : i; 
        for(;i < str.size() && isdigit(str[i]);i++){
            if(result > (INT_MAX - str[i] + '0')/10)
                return isNegativeNumber ? INT_MIN : INT_MAX;
            result = result * 10  - '0' +str[i]; 
        }
        return isNegativeNumber ? -result : result;
    }
};


int main(int argc,char* argv[]){


    return 0;
}