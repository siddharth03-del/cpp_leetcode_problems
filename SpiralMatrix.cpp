#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<int> ans;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        ans.push_back(matrix[0][0]);
        matrix[0][0] = -200;
        f(matrix, 0, 0, 0);
        return ans;
    }
    void f(vector<vector<int>>& matrix, int direction, int row, int col){
        int n = row + directions[direction][0];
        int m = col + directions[direction][1];
        if(!(n >= 0 && n < matrix.size() && m >= 0 && m < matrix[0].size())){
            if(direction == 0){
            n = n + directions[2][0];
            m = m + directions[2][1];
            f(matrix, 1, n, m);
            return;
        }
        else if(direction == 1){
            n = n + directions[3][0];
            m = m + directions[3][1];
            f(matrix, 2, n, m);
            return;
        }
        else if(direction == 2){
            n = n + directions[0][0];
            m = m + directions[0][1];
            f(matrix, 3, n, m);
            return;
        }
        else{
            n = n + directions[1][0];
            m = m + directions[1][1];
            f(matrix, 0, n, m);
            return;
        }
        }
        if(matrix[n][m] == -200){
            return;
        }
        while(matrix[n][m] != -200 && n >= 0 && n < matrix.size() && m >= 0 && m < matrix[0].size()){
            ans.push_back(matrix[n][m]);
            matrix[n][m] = -200;
            n = n + directions[direction][0];
            m = m + directions[direction][1];
        }
        if(direction == 0){
            n = n + directions[2][0];
            m = m + directions[2][1];
            f(matrix, 1, n, m);
        }
        else if(direction == 1){
            n = n + directions[3][0];
            m = m + directions[3][1];
            f(matrix, 2, n, m);
        }
        else if(direction == 2){
            n = n + directions[0][0];
            m = m + directions[0][1];
            f(matrix, 3, n, m);
        }
        else{
            n = n + directions[1][0];
            m = m + directions[1][1];
            f(matrix, 0, n, m);
        }
        return;
    }
};