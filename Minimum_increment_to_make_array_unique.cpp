#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution{
public:
    int minIncrementForUnique(vector<int>& nums){
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        int count = 0;
        int last;
        for(int i = 0; i < nums.size(); i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]] = 1;
                last = nums[i];
            }
            else{
                int target = last + 1;
                count += abs(nums[i] - target);
                freq[target] = 1;
                last = target;
            }
        }
        return count;
    }
};
