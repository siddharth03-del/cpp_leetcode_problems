#include <vector>
using namespace std;
class Solution{
    public:
    int minSubArrayLen(int target, vector<int>& nums){
        int left = 0;
        int right = nums.size() - 1;
        int len =0;
        while(right >= left){
            int mid = right+left/2;
            bool val = f(nums, mid, target);
            if(val){
                len = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return len;
    }
    bool f(vector<int>& nums, int size, int target){
        int i = 0;
        int j = 0;
        long long sum = 0;
        for(j; j < size; j++){
            sum += nums[j];
        }
        while(j < nums.size()){
            if(sum >= target){
                return true;
            }
            else{
                sum -= nums[i];
                i++;
                j++;
                sum += nums[j];
            }
        }
        return false;
    }
};