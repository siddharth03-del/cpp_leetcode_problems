#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int smallestDistancePair(vector<int>& nums, int k){
        int ans;
        sort(nums.begin(), nums.end());
        int right = nums[nums.size() - 1] - nums[0];
        int left = min((nums[1] - nums[0]), (nums[nums.size()-1] - nums[nums.size() - 2]));
        while(right >= left){
            int mid = (right + left) / 2;
            int total = count(nums, mid);
            if(total > k){
                right = mid - 1;
                ans = mid;
            }
            else if(total < k){
                left = mid + 1;
            }
            else{
                ans = mid;
            }
        }
        return search(nums, ans);
    }
    int count(vector<int> nums, int x){
        int total = 0;
        for(int i = 0; i < nums.size()-1; i++){
            int left = i+1;
            int right = nums.size() - 1;
            int temp = 0;
            while(right >= left){
                int mid = (right + left)/2;
                if(nums[mid] - nums[i] > x){
                    right = mid - 1;
                }
                else if(nums[mid] - nums[i] <= x){
                    
                    temp = mid - i;
                    left = mid + 1;
                }
            }
            total += temp;
        }
        return total;
    }
    int search(vector<int>& nums, int x){
        int ans = 0;
        for(int i = 0; i < nums.size()-1; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(right >= left){
                int mid = (right + left) / 2;
                if(nums[mid] - nums[i] > x){
                    right = mid - 1;
                }
                else if(nums[mid] - nums[i] < x){
                    if(nums[mid] - nums[i] > ans){
                        ans = nums[mid] - nums[i];
                    }
                    left = mid + 1;
                }
                else if(nums[mid] - nums[i] == x){
                    ans = nums[mid] - nums[i];
                    return ans;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> num = {1,6,1};
    cout << s.smallestDistancePair(num, 2);
    return 0;
}