#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<int> coin;
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount){
        sort(coins.begin(), coins.end());
        coin = coins;
        dp.resize(10005, -1);
        int a = f(amount);
        if(a > 0){
            return a;
        }
        else{
            return -1;
        }
        return -1;
    }
    int f(int amount){
        if(dp[amount] != -1){
            return dp[amount];
        }
        int i = 0;
        int smallest = __INT_MAX__;
        if(amount > coin[i]){
            int a = f(amount - coin[i]) + 1;
            if(a < smallest){
                smallest = a;
            }
            i++;
        }
        if(smallest == __INT_MAX__){
            return dp[amount] = -10005;
        }
        return dp[amount] = smallest;
    }
};