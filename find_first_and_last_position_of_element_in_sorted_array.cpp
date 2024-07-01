#include <vector>
using namespace std;
class Solution{
    public:
    int extreme(vector<int>& nums, int target, bool is_searchleft){
        int left = 0;
        int right = nums.size() -1 ;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                ans = mid;
                if(is_searchleft){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        int left = -1;
        int right = -1;
        left = extreme(nums, target , true);
        right = extreme(nums, target, false);
        return {left, right};
    }
};