#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution{
    public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums){
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int newn = 0;
            if(num == 0){
                newn = mapping[num];
            }
            while(num > 0){
                int r = num % 10;
                int g = mapping[r];
                newn = newn * 10 + g;
                num = num / 10;
            }
            
            mp[newn].push_back(nums[i]);
        }
        vector<int> keys;
        for (const auto& kv : mp) {
        keys.push_back(kv.first);
        }
        sort(keys.begin(), keys.end());
        vector<int> res;
        for(int i = 0; i < keys.size(); i++){
            for(int j = 0; j < mp[keys[i]].size(); j++){
                res.push_back(mp[keys[i]][j]);
            }
        }
        return res; 
    }
};