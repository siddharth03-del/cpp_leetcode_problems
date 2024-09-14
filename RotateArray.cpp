#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution{
    public:
    void rotate(vector<int>& nums, int k){
        vector<int>ans(nums.size(), -1);
        int n = nums.size();
        int original = k % n;
        for(int i = 0; i < n; i++){
            int idx = original + i;
            if(idx >= n){
                idx = idx - n;
            }
            ans[idx] = nums[i];
        }
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        }
        return;
    }
};