#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1,true);
        prime[0] = prime[1] = false;
        for(int i = 2;i <= n;i++){
            if(prime[i] == true){
                for(int j = 2*i;j <= n;j+=i){
                    prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(prime[i])
                cnt++;
        }
        return cnt;
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    int cnt = solution.countPrimes(10);
    cout << cnt << endl;
    return 0;
}