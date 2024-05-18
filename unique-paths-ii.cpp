#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> global;
vector<vector<int>> dp(102, vector<int>(102));
int f(int row, int col){
    if(global[row][col] == 1){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    if( row == (global.size() - 1) && col == (global[0].size() - 1) ){
        return 1;
    }
    else if(row == (global.size()-1)){
        return dp[row][col] =  f(row, col + 1);
    }
    else if( col == (global[0].size() - 1)){
        return dp[row][col] =  f(row + 1, col);
    }
    int a = f(row, col + 1);
    int b = f(row + 1, col);
    return dp[row][col] = a+b;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    for(int i = 0; i < (dp.size()-1); i++){
        for(int j = 0; j < (dp[0].size() - 1); j++){
            dp[i][j] = -1;
        }
    }
    global = obstacleGrid;
    f(0,0);
}
int main(){
    vector<vector<int>> input = {{0,1},{0,0}};
    cout<<uniquePathsWithObstacles(input);
    return 0;
}