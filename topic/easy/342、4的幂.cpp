#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ( (num & (num - 1)) == 0) && (num % 3 == 1);
    }
};
int main(int argc,char* argv[]){
    Solution solution;
    bool result = solution.isPowerOfFour(16);
    cout << result << endl;
    return 0;
}