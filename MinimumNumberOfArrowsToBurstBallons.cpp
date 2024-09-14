#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int findMinArrowShots(vector<vector<int>>& points){
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int arrows = 1;
        vector<int> last = points[0];
        for(int i = 1; i < points.size(); i++){
            if(last[1] >= points[i][0]){
                last = {points[i][0], min(last[1], points[i][1])};
                continue;
            }
            else{
                arrows++;
                last = points[i];
            }
        }
        return arrows;
    }
};