#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp(201, std::vector<int>(201, -1));
vector<vector<int>> global;
int f(int i,int j){
    if(dp[i][j] > 0){
        return dp[i][j];
    }
    if(i == (global.size()-1)){
        return global[i][j];
    }
    else{
        int a = global[i][j] + f(i+1,j);
        int b = global[i][j] + f(i+1,j+1);
        return dp[i][j] =  min(a, b);
    }
}
int minimumTotal(vector<vector<int>>& triangle){
    for (auto& row : dp) {
        fill(row.begin(), row.end(), -1);
    }
    global = triangle;
    return f(0,0);
}
int main(){
    vector<vector<int>> triangle = {{-10}};
    cout<<minimumTotal(triangle);
    return 0;
}