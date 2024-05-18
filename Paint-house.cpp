#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> global;
vector<vector<int>> dp
int f(int row, int col){
    if(row == (global.size()-1)){
        return global[row][col];
    }
    if( col == 0){
        return global[row][col] + min(f(row + 1, col + 1) , f(row + 1, col + 2));
    }
    else if(col == 1){
        return global[row][col] + min(f(row + 1, col - 1) , f(row + 1, col + 1));
    }
    else if(col == 2){
        return global[row][col] + min(f(row + 1, col - 2) , f(row + 1, col-1));
    }
    return 0;
}
int minCost(vector<vector<int>>& costs){
    global = costs;
    int a = costs[0][0] + min(f(1,1) , f(1,2));
    int b = costs[0][1] + min(f(1,0) , f(1,2));
    int c = costs[0][2] + min(f(1,0) , f(1,1));
    return min(a, min(b,c));
}
int main(){
    vector<vector<int>> input = {{14,2,11},{11,14,5},{14,3,10}};
    cout<<minCost(input);
    return 0;
}