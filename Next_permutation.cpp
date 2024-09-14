#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
    public:
    void nextPermutation(vector<int>& nums){
        int longestsuffix = nums.size() - 1;
        while(longestsuffix > 0){
            if(nums[longestsuffix - 1] > nums[longestsuffix]){
                break;
            }
            longestsuffix --;
        }
        int pivot = longestsuffix - 1;
        int largest = longestsuffix;
        for(int i = longestsuffix; i < nums.size(); i++){
            if(nums[i] > nums[pivot] && nums[i] < nums[largest]){
                largest = i;
            }
        }
        int temp = nums[pivot];
        nums[pivot] = nums[largest];
        nums[largest] = temp;
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }
};
