#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int specialArray(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int first = 0;
    int last = nums.size();
    int mid = (first + last) / 2;
    int ans = -1;
    int lastindex = nums.size() - 1;
    while(mid != 0){
        mid = (last + first ) / 2;
        if(nums[lastindex - mid + 1] >= mid){
            if(lastindex - mid + 1  > 0){
                if(nums[lastindex - mid] < mid ){
                    ans = mid;
                    break;
                }
            }
            else{
                ans = mid;
                break;
            }
        }
        if(nums[lastindex - mid + 1] < mid){
            if(mid == 0){
                break;
            }
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {0,0};
    cout <<specialArray(nums);
    return 0;
}