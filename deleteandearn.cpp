#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> frequencymap(5, 0);
vector<int> dp(10000, -1);
int f(int num){
    if(dp[num] > 0){
        return dp[num];
    }
    else if(num >= (frequencymap.size())){
        return 0;
    }
    else if(num == (frequencymap.size() - 1)){
        return (frequencymap[num]*num);
    }
    else{
        int a = (frequencymap[num]*num) + f(num + 2);
        int b = (frequencymap[num]*num) + f(num + 3);
        dp[num] = max(a,b);
        return dp[num];
    }
}
int deleteAndEarn(vector<int>& nums){
    // dp.fill(dp.begin(), dp.end(), -1);
    int i = 0;
    while(i < nums.size()){
        (frequencymap[nums[i]])++;
        i++;
    }
    int a =  f(1);
    int b = f(2);
    return max(a, b);
}
int main(){
    vector<int> nums = {2,2,3,3,3,4};
    cout<< deleteAndEarn(nums);
    return 0;
}