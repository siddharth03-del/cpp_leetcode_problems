#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp(1001, -1);
vector<int> s;
int f(int day){
    if(dp[day] > 0){
        return dp[day];
    }
    if(day >= (s.size())){
        return 0;
    }
    else if(day == (s.size()-1)){
        return s[day];
    }
    else{
        int a = s[day] + f(day + 1);
        int b = s[day] + f(day + 2);
        dp[day] = min(a, b);
        return dp[day];
    }
}
int minCostClimbingStairs(vector<int>& cost){
    s = cost;
    int a = f(0);
    int b = f(1);
    return min(a, b);
}
int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<minCostClimbingStairs(cost);
    return 0;
}