#include <algorithm>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> ans;
        int i = 0;
        for(i; i < intervals.size(); i++){
            if(newInterval[0] <= intervals[i][0]){
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int> last = ans.back();
            if(intervals[i][0] >= last[1]){
                last[1] = max(last[1], intervals[i][1]);
                ans.push_back(last);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};