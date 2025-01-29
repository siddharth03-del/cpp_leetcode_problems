#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int maxProduct(vector<int>& nums){
        vector<int> prod;
        prod.push_back(nums[0]);
        int min = nums[0];
        int max = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prod.push_back(nums[i]*prod[i-1]);
        }
        for(int i = 1; i < prod.size(); i++){
            if(prod[i] > 0){
                if(prod[i] > ans){
                    ans = prod[i];
                    max = prod[i];
                }
            }
            else if(prod[i] < 0){
                int temp = prod[i] / min;
                if(temp > ans){
                    ans = temp;
                }
                if(prod[i] < min){
                    min = prod[i];
                }
            }
        }
        return ans;
    }
};