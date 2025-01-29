#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n){
        vector<int> temp;
        f(temp, n, k, 1);
        return res;
    }
    void f(vector<int>& temp, int target, int k, int start){
        if(target == 0 && temp.size() == k){
            res.push_back(temp);
            return;
        }
        if(target == 0){
            return;
        }
        if(temp.size() >= k){
            return;
        }
        for(int i = start; i < 10; i++){
            if(find(temp.begin(), temp.end(), i) == temp.end()){
                vector<int> v = temp;
                v.push_back(i);
                f(v, target - i, k, i + 1);
            }
        }
        return;
    }
};