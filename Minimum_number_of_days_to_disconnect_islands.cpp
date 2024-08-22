#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int minDays(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> neighbours = {{1,0},{0,1},{-1,0},{0,-1}};
        int minimal = __INT_MAX__;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] = 1){
                    int count = 0;
                    int n1[2] = {i-1, j};
                    int n2[2] = {i,j-1};
                    int n3[2] = {i+1,j};
                    int n4[2] = {i,j+1};
                    if(n1[0] >= 0){
                        if(grid[n1[0]][n1[1]] == 1){
                            count++;
                        }
                    }
                    if(n2[1] >= 0){
                        if(grid[n2[0]][n2[1]] == 1){
                            count++;
                        }
                    }
                    if(n3[0] < rows){
                        if(grid[n3[0]][n3[1]] == 1){
                            count++;
                        }
                    }
                    if(n4[1] < cols){
                        if(grid[n4[0]][n4[1]] == 1){
                            count++;
                        }
                    }
                    if(count < minimal){
                        minimal = count;
                    }
                }
            }
        }
        if(minimal == 0){
            return 0;
        }
        else if(minimal == 1){
            return 1;
        }
        else if(minimal >= 2){
            return 2;
        }
        return 0;
    }
};