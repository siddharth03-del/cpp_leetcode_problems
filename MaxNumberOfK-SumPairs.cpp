#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int maxOperations(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;
        while(j > i){
            if(nums[i] + nums[j] < k){
                i++;
            }
            else if(nums[i] + nums[j] > k){
                j--;
            }
            else{
                count++;
                i++;
                j--;
            }
        }
        return count;
    }
};