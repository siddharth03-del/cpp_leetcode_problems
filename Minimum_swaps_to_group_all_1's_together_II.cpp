#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int minSwaps(vector<int>& nums){
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                total++;
            }
        }
        int j = total;
        int i = 1;
        int count = 0;
        for(int k = 0; k < j ; k++){
            if(nums[k] == 0){
                count++;
            }
        }
        int swaps = count;
        int ans = swaps;
        while(j < nums.size()){
            if(nums[j] == 0){
                swaps++;
            }
            j++;
            if(nums[i - 1] == 0){
                swaps--;
            }
            i++;
            if(swaps < ans){
                ans = swaps;
            }
        }
        j = 0;
        while(i < nums.size()){
            if(nums[j] == 0){
                swaps++;
            }
            j++;
            if(nums[i-1] == 0 ){
                swaps--;
            }
            i++;
            if(swaps < ans){
                ans = swaps;
            }
        }
        return ans;
    }
};