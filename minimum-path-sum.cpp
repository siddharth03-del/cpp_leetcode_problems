#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> global;
vector<vector<int>> dp(202, vector<int>(202));
int f(int row, int col){
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    if( row == (global.size() - 1) && col == (global[0].size() - 1) ){
        return global[row][col];
    }
    else if(row == (global.size()-1)){
        return dp[row][col] =  global[row][col] + f(row, col + 1);
    }
    else if( col == (global[0].size() - 1)){
        return dp[row][col] =  global[row][col] + f(row + 1, col);
    }
    int a = global[row][col] + f(row + 1, col);
    int b = global[row][col] + f(row, col + 1);
    return dp[row][col] = min(a, b);
}
int minPathSum(vector<vector<int>>& grid){
    for(int i = 0; i < (dp.size()-1); i++){
        for(int j = 0; j < (dp[0].size() - 1); j++){
            dp[i][j] = -1;
        }
    }
    global = grid;
    if(grid.size() == 1 && grid[0].size() == 1){
        return grid[0][0];
    }
    else if(grid.size() == 1){
        return grid[0][0] + f(0,1);
    }
    else if(grid[0].size() == 1){
        return grid[0][0] + f(1,0);
    }
    int a = grid[0][0] + f(0,1);
    int b = grid[0][0] + f(1,0);
    return min(a,b);
}
int main(){
    vector<vector<int>> input = {{9,1,4,8}};
    cout<<minPathSum(input)<<endl;
    return 0;
}