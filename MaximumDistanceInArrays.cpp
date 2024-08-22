#include <algorithm>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution{
    public:
    int maxDistance(vector<vector<int>>& arrays){
        int n = arrays.size();
        vector<int> max(2);
        vector<int> min(2);
        int maxindex = 0;
        int minindex = 0;
        max[0] = arrays[0][arrays[0].size() - 1];
        min[0] = arrays[0][0];
        max[1] = arrays[1][arrays[1].size() - 1];
        min[1] = arrays[1][0];
        for(int i = 1; i < arrays.size(); i++){
            if(arrays[i][0] < min[0]){
                min[1] = min[0];
                min[0] = arrays[i][0];
                minindex = i;
            }
            else{
                if(arrays[i][0] <= min[1]){
                    min[1] = arrays[i][0];
                }
            }
            if(arrays[i][arrays[i].size() - 1] > max[0]){
                max[1] = max[0];
                max[0] = arrays[i][arrays[i].size() - 1];
                maxindex = i;
            }
            else{
                if(arrays[i][arrays[i].size() - 1] >= max[0]){
                    max[1] = arrays[i][arrays[i].size() - 1];
                }
            }
        }
        if(maxindex != minindex){
            return abs(max[0] - min[0]);
        }
        else{
            int a = abs(max[0] - min[1]);
            int b = abs(max[1] - min[0]);
            if(a > b){
                return a;
            }
            else{
                return b;
            }
        }
        return 0;
    }
};