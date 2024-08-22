#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    vector<int> candidate;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        candidate = candidates;
        unordered_map<int, int> call;
        for(int i =0; i < candidates.size(); i++){
            if(candidates[i] <= target){
                if(call[candidates[i]]){
                    continue;
                }
                else{
                    call[candidates[i]] = 1;
                    fun({candidates[i]}, i, target - candidates[i]);
                }
            }
        }
    }
    void fun(vector<int> res,int index, int target){
        if(target == 0){
            result.push_back(res);
            return;
        }
        unordered_map<int, int> call;
        for(int i = index + 1; i < candidate.size(); i++){
            if(candidate[i] <= target){
                if(call[candidate[i]]){
                    continue;
                }
                else{
                    call[candidate[i]] = 1;
                    vector<int> num = res;
                    num.push_back(candidate[i]);
                    fun(num, i, target - candidate[i]);
                }
            }
        }
        return;
    }
};