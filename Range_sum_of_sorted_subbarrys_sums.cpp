#include <algorithm>
#include <vector>
using namespace std;
class Solution{
    public:
    int rangeSum(vector<int>& nums, int n , int left, int right){
        vector<int> prefixsum;
        int sum = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            prefixsum.push_back(sum);
            ans.push_back(sum);
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                ans.push_back(prefixsum[j]-prefixsum[i-1]);
            }
        }
        sort(ans.begin(), ans.end());
        long long r = 0;
        left-=1;
        for(int i = left; i < right; i++){
            r+=ans[i];
        }
        return r % 1000000007;
    }
};