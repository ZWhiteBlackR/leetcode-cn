#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y)return false;
        if(z == x || z == y)return true;
        if(x == 0 || y == 0)return false;
        return z % __gcd(x,y) == 0;
    }
};

int main(int argc,char* argv[]){

    return 0;
}