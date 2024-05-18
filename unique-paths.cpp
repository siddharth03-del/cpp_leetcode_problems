#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp(202, vector<int>(202));
int m1;
int n1;
int f(int row, int col){
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    if(row == m1 || col==n1){
        return 1;
    }
    if(row == m1){
        return dp[row][col] = f(row, col + 1);
    }
    else if(col == n1){
        return dp[row][col] = f(row + 1, col);
    }
    int a = f(row, col + 1);
    int b = f(row + 1, col);
    return dp[row][col] = a+b;
}
int uniquePaths(int m, int n){
    for(int i = 0; i < (dp.size()-1); i++){
        for(int j = 0; j < (dp[0].size() - 1); j++){
            dp[i][j] = -1;
        }
    }
    m1 = m;
    n1 = n;
    if(m == 1 || n == 1){
        return 1;
    }
    return f(1,1);
}
int main(){
    cout<<uniquePaths(3,7);
    return 0;
}