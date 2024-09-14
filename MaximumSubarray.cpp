#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int maxSubArray(vector<int>& nums){
        int maxSum =  -__INT_MAX__;
        int prefixsum = 0;
        int small = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixsum += nums[i];
            if(prefixsum - small > maxSum){
                maxSum = prefixsum - small;
            }
            if(prefixsum < small){
                small = prefixsum;
            }
        }
        return maxSum;
    }
};