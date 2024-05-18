#include <iostream>
#include <vector>
using namespace std;
vector<int> global;
vector<int> dp(2503, 0);
int f(int index){
    for(int j=0; j<index; j++){
        if(global[j] < global[index]){
            if((dp[j] + 1) > dp[index]){
            dp[index] = (dp[j] + 1);
        }
        }
    }
    if(dp[index] == 0){
        dp[index] = 1;
    }
}
int lengthofLIS(vector<int>& nums){
    global = nums;
    dp[0] = 1;
    if(nums.size() == 1){
        return 1;
    }
    for(int i =1; i < nums.size(); i++){
        f(i);
    }
    int max = dp[1];
    for(int i = 1; i<dp.size(); i++){
        if(dp[i] > max){
            max = dp[i];
        }
    }
    return max;
}
int main(){
    vector<int> nums = {0};
    cout<<lengthofLIS(nums);
    return 0;
}