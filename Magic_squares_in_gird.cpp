#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution{
    public:
    int numMagicSquaresInside(vector<vector<int>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        if(row < 3 || col < 3){
            return 0;
        }
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isMagicSquare(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
    bool isMagicSquare(vector<vector<int>> grid, int row, int col){
        if(row + 2 < grid.size() && col + 2 < grid[0].size()){
            int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
            int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
            int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
            int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
            int row2 = grid[row + 1][col] + grid[row + 1][col+1] + grid[row +1][col+2];
            int row3 = grid[row+2][col] + grid[row +2][col + 1] + grid[row+2][col + 2];
            int dia1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
            int dia2 = grid[row][col +2] + grid[row + 1][col + 1] + grid[row+2][col];
            if(col1 == col2 && col1 == col3 && col1 == row1 && col1 == row2 && col1 == row3 && col1 == dia1 && col1 == dia2){
                set<int> s({1,2,3,4,5,6,7,8,9});
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        s.erase(grid[row+i][col + j]);
                    }
                }
                return s.empty();
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
        return false;
    }
};