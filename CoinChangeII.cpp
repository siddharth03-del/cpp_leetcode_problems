#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> dp;
    vector<int> coin;
    int change(int amount, vector<int>& coins){
        dp.resize(305, vector<int>(5005, -1));
        coin = coins;
        return f(0, amount);
    }
    int f(int i, int amt){
        if(dp[i][amt] != -1){
            return dp[i][amt];
        }
        if(amt == 0){
            return 1;
        }
        if(i >= coin.size()){
            return 0;
        }
        int a = f(i + 1, amt);
        int b = 0;
        if(amt >= coin[i]){
            b = f(i, amt-coin[i]);
        }
        dp[i][amt] = a+b;
        return a + b;
    }  
};