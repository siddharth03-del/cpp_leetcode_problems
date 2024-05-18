#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& nums){
    if(nums.size() == 1){
        return nums[0];
    }
    int left = 0;
    int right = nums.size() - 1;
    int min = 0;
    int max = nums.size() - 1;
    int mid;
    int pivot;
    while(max >= min){
        mid = (max - min)/2 + min;
        if(nums[mid] >= nums[left]){
            pivot = mid;
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    if(pivot == nums.size() - 1){
        return nums[0];
    }
    return nums[pivot + 1];
}
int main(){
    vector<int> nums = {2,1};
    cout<<findMin(nums)<<endl;
    return 0;
}