#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> s;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            s[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(const auto&pair : s){
            ans.push_back(pair.second);
        }
        return ans;
    }
};