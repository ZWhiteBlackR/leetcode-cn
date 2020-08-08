#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 2)
            return false;
        int cnt = 1;
        for(int i = 2;i < sqrt(num);i++){
            if(num % i == 0){
                cnt += i;
                cnt += num / i;
            }
            if(cnt > num)
                return false;
        }
        return num == cnt;
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    bool result = solution.checkPerfectNumber(28);
    cout << result << endl;
}