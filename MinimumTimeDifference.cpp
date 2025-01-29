#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times;
        for(int i = 0; i < timePoints.size(); i++){
            string h = "";
            h = timePoints[i][0] + timePoints[i][1];
            int hour = stoi(h);
            string m = "";
            m = timePoints[i][3] + (timePoints[i][4];
            int minute = stoi(m);
            times.push_back(hour * 60 + minute);
        }
        sort(times.begin(), times.end());
        if(times.size() <= 2){
            int a = times[1] - times[0];
            int b = 24*60 - times[1] + times[0];
            return min(a, b);
        }
        int minn = 24*60;
        for(int i = 0; i < times.size() - 1; i++){
            int a = times[i+1] - times[i];
            if(a < minn){
                minn = a;
            }
        }
        int a = 24*60 - times[times.size()-1] + times[0];
        return min(a, minn);
    }
};