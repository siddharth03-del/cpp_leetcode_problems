#include <vector>
using namespace std;
class Solution{
    vector<int> dp;
    int countGoodStrings(int low, int high, int zero, int one){
        dp.resize(100005, -1);
        return f(0, low, high, zero, one) % 1000000007;
    }
    int f(int index, int low, int high , int zero, int one){
        if(index > high){
            return 0;
        }
        if(dp[index] != 0){
            return dp[index];
        }
        if(index >= low && index <= high){
            int a = f(index + zero, low, high, zero, one) % 1000000007;
            int b = f(index + one, low, high, zero, one) % 1000000007;
            return dp[index] = (a + b + 1)% 1000000007;
        }
        else{
            int a = f(index + zero, low, high, zero, one) % 1000000007;
            int b = f(index + one, low, high, zero, one) % 1000000007;
            return dp[index] = (a + b)% 1000000007;
        }
        return 0;
    }
};