#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int>& nums,int target){
    int left = 0;
    int right = nums.size() - 1;
    int min = 0;
    int max = nums.size() - 1;
    int mid;
    int pivot;
    mid = (max - min)/2 + min;
    if( nums.size() == 1){
        if(nums[0] == target){
            return true;
        }
        else{
            return false;
        }
    }
    if( nums[mid] == nums[left] && nums[right] == nums[mid]){
        for(int i = 0; i < right - 1; i++){
            if( nums[i] > nums[i+1]){
                pivot = i;
            }
        }
    }
    else{
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
                return true;
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
                return true;
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
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1,1,1,1,3,1};
    cout<<search(nums, 3);
    return 0;
}