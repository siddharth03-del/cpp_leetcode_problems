#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution{
    public:
    int minDifference(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int minvalue = INT_MAX;
        if(nums.size() <= 4){
            return 0;
        }
        minvalue = min(minvalue, nums[nums.size() - 4] - nums[0]);
        minvalue = min(minvalue, nums[nums.size()-1] - nums[3]);
        minvalue = min(minvalue, nums[nums.size()-2] - nums[2]);
        minvalue = min(minvalue, nums[nums.size()-3] - nums[1]);
        return minvalue;
    }
};