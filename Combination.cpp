#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k){
        for(int i = 0; i <= n; i++){
            vector<int> temp = {i};
            combinations(n, k, i + 1, temp);
        }
        return ans;
    }
    void combinations(int n, int k, int i, vector<int>& arr){
        if(arr.size() == k){
            ans.push_back(arr);
            return;
        }
        if(k - arr.size() > n - i - 1){
            return;
        }
        for(int j = i; j <= n; j++){
            vector<int> temp = arr;
            temp.push_back(j);
            combinations(n, k, i+1, temp);
        }
        return;
    }
};