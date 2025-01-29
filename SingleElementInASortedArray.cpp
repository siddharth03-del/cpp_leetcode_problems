#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int start, int end){
        if(start > end){
            return -1;
        }
        int mid = (start + end) / 2;
        if(mid == 0 || mid == nums.size() -1){
            if(mid == 0){
                if(nums[mid] != nums[mid + 1]){
                    return nums[mid];
                }
            }
            else{
                if(nums[mid] != nums[mid - 1]){
                    return nums[mid];
                }
            }
        }
        else{
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }
        }
        int a = search(nums, mid + 1, end);
        int b = search(nums, start, mid - 1);
        if(a != -1){
            return a;
        }
        else{
            return b;
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
};