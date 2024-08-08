#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> ans;
    int n;
    int m;
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart){
        n = rows;
        m = cols;
        fun(1, 0, rStart, cStart);
        return ans;
    }
    void fun(int moves, int direction,int row, int col){
        if(ans.size() == n*m){
            return;
        }
        if(direction == 0){
            for(int i = col; i < col + moves; i++){
                if((i >= 0 && i < m) && (row >= 0 && row < n)){
                    ans.push_back({row, i});
                }
            }
            fun(moves, 1, row, col + moves);
        }
        else if(direction == 1){
            for(int i = row; i < row + moves; i++){
                if((i >= 0 && i < n) && (col >= 0 && col < m)){
                    ans.push_back({i, col});
                }
            }
            fun(moves + 1, 2, row + moves, col);
        }
        else if(direction == 2){
            for(int i = col; i > col - moves; i--){
                if((i >= 0 && i < m) && (row >= 0 && row < n)){
                    ans.push_back({row, i});
                }
            }
            fun(moves, 3, row, col - moves);
        }
        else if(direction == 3){
            for(int i = row; i > row - moves; i--){
                if((i >= 0 && i < n) && (col >= 0 && col < m)){
                    ans.push_back({i, col});
                }
            }
            fun(moves + 1, 0, row - moves, col);
        }
        return;
    }
};