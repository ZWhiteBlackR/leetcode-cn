#include<bits/stdc++.h>
using namespace std;

/*
 * 题目描述：
 * 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
 * 顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
 * 每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每* 个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
 * 注意，一开始你手头没有任何零钱。
 * 如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
 */

/*
 * 解题思路：
 * 记录找钱过程中5和10的个数，分三种情况进行讨论
 */
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCnt = 0,tenCnt = 0;
        for(int i = 0;i < bills.size();i++){
            if(bills[i] == 5)
                fiveCnt++;
            else if(bills[i] == 10){
                if(fiveCnt == 0)
                    return false;
                fiveCnt--;
                tenCnt++;
            }else{
                if(tenCnt >= 1 && fiveCnt >= 1){
                    tenCnt--,fiveCnt--;
                }else if(fiveCnt >= 3){
                    fiveCnt -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};