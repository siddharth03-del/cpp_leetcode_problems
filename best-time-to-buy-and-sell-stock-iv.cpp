#include <iostream>
#include <vector>
using namespace std;
vector<int> global;
vector<vector<vector<int>>> dp(1005, vector<vector<int>>(3, vector<int>(105)));
int f(int i, bool on, int K){
    //base case
    if( dp[i][on][K] != -1){
        return dp[i][on][K];
    }
    if(i == (global.size()-1)){
        if( on == true){
            return dp[i][on][K] = global[i];
        }
        else{
            return 0;
        }
    }
    if(K == 0){
        return 0;
    }
    int a;
    int b;
    a = f(i+1, on, K);
    if(on == false){
        b = -global[i] + f(i+1, true, K);
    }
    else{
        b = global[i] + f(i+1, false, K-1);
    }
    return dp[i][on][K] = max(a,b);
}
int maxProfit(int k, vector<int>& prices){
    global = prices;
    for( int i = 0; i < global.size(); i++){
        for (int j = 0; j < 2; j++){
            for(int k = 0; k < 105; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    return f(0, false, k);
}
int main(){
    vector<int> input = {3,2,6,5,0,3};
    cout<< maxProfit(2, input);
    return 0;
}