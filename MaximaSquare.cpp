#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int maximalSquare(vector<vector<char>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        int largest = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    int a = i + 1;
                    int b = j + 1;
                    dp[a][b] = min(dp[a-1][b-1] , min(dp[a][b-1], dp[a-1][b]))+ 1;
                    if(dp[a][b] > largest){
                        largest = dp[a][b];
                    }
                }
            }
        }
        return largest;
    }
};