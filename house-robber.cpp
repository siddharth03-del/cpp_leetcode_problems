#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp(101,-1);
vector<int> s;
int f(int day){
    if(dp[day] > 0){
        return dp[day];
    }
    else if(day == (s.size()-1)){
        return s[day];
    }
    else if(day >=s.size()){
        return 0;
    }
    else{
        int a = s[day] + f(day + 2);
        int b = s[day] + f(day + 3);
        dp[day] = max(a,b);
        return dp[day];
    }
}
int rob(vector<int>& nums){
    s = nums;
    int a = f(0);
    int b = f(1);
    return max(a,b);
}
int main(){
    vector<int> cost = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout<<rob(cost)<<endl;
    return 0;
}