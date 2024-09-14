#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> ans;
    vector<int> num;
    vector<vector<int>> permute(vector<int>& nums){
        num = nums;
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp;
            vector<int> a = nums;
            a.erase(a.begin() + i);
            temp.push_back(nums[i]);
            f(temp, nums.size(), a);
        }
        return ans;
    }
    void f(vector<int>& array, int n, vector<int>& nums){
        if(array.size() == n){
            ans.push_back(array);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp = array;
            vector<int> a = nums;
            a.erase(a.begin() + i);
            temp.push_back(nums[i]);
            f(temp, n, a);
        }
        return;
    }
};