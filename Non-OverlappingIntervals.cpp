#include <vector>
#include <algorithm>
using namespace std;
struct Compare{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]){
            return true;
        }
        else if(a[0] == b[0]){
            return a[1] < b[1];
        }
        else{
            return false;
        }
    }
};
class Solution{
    public:
    vector<int> dp;
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), Compare());
        dp.resize(intervals.size()+5, -1);
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        return f(intervals, ans, 1);
    }
    int f(vector<vector<int>>& intervals, vector<vector<int>>& ans ,int index){
        if(index >= intervals.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        if(ans.back()[1] > intervals[index][0]){
            vector<vector<int>> temp = ans;
            temp.pop_back();
            temp.push_back(intervals[index]);
            int r1 = f(intervals, ans, index + 1) + 1;
            int r2 = f(intervals, temp, index+1) + 1;
            return dp[index] = min(r1, r2);
        }
        ans.push_back(intervals[index]);
        return dp[index] = f(intervals, ans, index + 1);
    }
};