#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<int> price;
    vector<vector<int>>dp;
    int maxProfit(vector<int>& prices){
        price = prices;
        dp.resize(5005, vector<int>(1003, -1));
        return f(0, 1001);
    }
    int f(int index, int stock){
        if(dp[index][stock] != -1){
            return dp[index][stock];
        }
        if(index >= price.size()){
            return 0;
        }
        if(stock != 1001){
            int a = f(index + 2, 1001) + price[index] - stock;
            int b = f(index + 1,stock);
            return dp[index][stock] = max(a, b);
        }
        else{
            int a = f(index + 1,price[index]);
            int b = f(index + 1, 1001);
            return dp[index][stock] = max(a,b);
        }
        return 0;
    }
};