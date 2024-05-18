#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() -1;
    int mid;
    while(low <= high){
        mid = (low + high) /2;
        if(target < nums[mid]){
            high = mid - 1;
        }
        else if(target > nums[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    if(mid == 0){
        if(target < nums[mid]){
            return mid;
        }
        else{
            return mid + 1;
        }
    }
}
int main(){
    vector<int> nums = {1,3,5,6};
    cout<<searchInsert(nums, 2);
    return 0;
}