#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        vector<int> rowmin;
        vector<int> colmax;
        for(int i = 0; i < m; i++){
            int min = matrix[i][0];
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < min){
                    min = matrix[i][j];
                }
            }
            // cout << min << endl;
            rowmin.push_back(min);
        }
        for(int i = 0; i < n; i++){
            int max = matrix[i][0];
            for(int j =0; j < m; j++){
                if(matrix[j][i] > max){
                    max = matrix[j][i];
                }
            }
            // cout << max << endl;
            colmax.push_back(max);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rowmin[i] == colmax[j]){
                    res.push_back(rowmin[i]);
                }
            }
        }
        return res;
    }
};
