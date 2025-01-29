#include <vector>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int m = coordinates[1][1] - coordinates[0][1] / coordinates[1][0] - coordinates[0][0];
        int a = __INT_MAX__;
        for(int i = 2; i < coordinates.size(); i++){
            int x1 = coordinates[i-1][0];
            int x2 = coordinates[i][0];
            int y1 = coordinates[i-1][1];
            int y2 = coordinates[i][1];
            int slope = y2 - y1 / x2 - x1;
            if(slope != m){
                return false;
            } 
            else{
                m = slope;
            }
        }
        return true;
    }
};