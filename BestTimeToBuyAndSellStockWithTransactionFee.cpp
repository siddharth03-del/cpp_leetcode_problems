#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> price;
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices, int fee){
        price = prices;
        dp.resize(50005, vector<int>(50005, -1));
        return f(0,0);
    }
    int f(int index, int stock){
        if(index >= price.size()){
            return 0;
        }
        if(dp[index][stock] != -1){
            return dp[index][stock];
        }
        if(stock == 0){
            int a = f(index + 1, price[index]);
            int b = f(index + 1, 0);
            return dp[index][stock] = max(a,b);
        }
        else{
            int a = f(index + 1, 0) + stock - price[index] - 2;
            int b = f(index + 1, stock);
            return dp[index][stock] = max(a, b);
        }
        return 0;
    }
};