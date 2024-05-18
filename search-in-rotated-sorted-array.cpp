#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target){
    if(nums.size() == 1){
        if(nums[0] == target){
            return 0;
        }
        else{
            return -1;
        }
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
        min = 0;
        max = pivot;
        while(min <= max){
            mid = (max - min)/2 + min;
            if(nums[mid]> target){
                max = mid - 1;
            }
            else if(nums[mid ] < target){
                min = mid + 1;
            }
            else{
                return mid;
            }
        }
    }
    else if( target >= nums[left] && target <= nums[pivot]){
        min = 0;
        max = pivot;
        while(min <= max){
            mid = (max - min)/2 + min;
            if(nums[mid]> target){
                max = mid - 1;
            }
            else if(nums[mid ] < target){
                min = mid + 1;
            }
            else{
                return mid;
            }
        }
    }
    else if( target <= nums[right] && target >= nums[pivot + 1]){
        min = pivot + 1;
        max = right;
        while(min <= max){
            mid = (max - min)/2 + min;
            if(nums[mid]> target){
                max = mid - 1;
            }
            else if(nums[mid ] < target){
                min = mid + 1;
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,3};
    cout<<search(nums, 0);
    return 0;
}