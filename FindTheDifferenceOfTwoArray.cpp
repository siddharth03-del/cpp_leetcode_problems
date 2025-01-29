#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int , bool>map1;
        unordered_map<int , bool>map2;
        for(int i = 0 ; i < nums1.size() ; i++){
            map1[nums1[i]] = true;
        }
        for(int i = 0; i < nums2.size(); i++){
            map2[nums2[i]] = true;
        }
        vector<vector<int>> ans;
        vector<int>r1;
        vector<int>r2;
        for(const auto& pair : map1){
            if(!map2[pair.first]){
                r1.push_back(pair.first);
            }
        }
        for(const auto& pair : map2){
            if(!map1[pair.first]){
                r2.push_back(pair.first);
            }
        }
        ans.push_back(r1);
        ans.push_back(r2);
        return ans;
    }
};  