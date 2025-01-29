#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int , int>freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        vector<vector<int>>v(100005, vector<int>());
        for(const auto& it: freq){
            v[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = v.size()-1; i >= 1; i--){
            for(int j = 0; j < v[i].size(); j++){
                ans.push_back(v[i][j]);
                k--;
            }
            if(k == 0) break;
        }
        return ans;
    }
};