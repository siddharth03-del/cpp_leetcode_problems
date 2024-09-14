#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> ans;
    vector<int> candidate;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        ans ={};
        candidate = candidates;
        vector<int> inp = {};
        f(target, 0, inp, 0);
        return ans;
    }
    void f(int target, int sum, vector<int>& arr, int idx){
        if(sum > target || idx >= candidate.size()){
            return;
        }
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        vector<int> array = arr;
        array.push_back(candidate[idx]);
        f(target, sum + candidate[idx], array , idx);
        f(target, sum , arr, idx + 1);
        return;
    }
};