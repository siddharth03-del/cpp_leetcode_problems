#include <vector>
using namespace std;
class Solution{
    public:
    void gameOfLife(vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> direction = {{-1.-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int live = 0;
                int dead = 0;
                for(int k = 0; k < direction.size(); k++){
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];
                    if(x >= 0 && x < m && y >= 0 && y < n &&){
                        if(board[x][y] == 1){
                            live++;
                        }
                        else{
                            dead++;
                        }
                    }
                }
                if(board[i][j] == 1){
                    if(live < 2){
                        ans[i][j] = 0;
                    }
                    else if(live == 2 || live == 3){
                        ans[i][j] = 1;
                    }
                    else if(live > 3){
                        ans[i][j] = 0;
                    }
                }else{
                    if(live == 3){
                        ans[i][j] = 1;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = ans[i][j];
            }
        }
    }
};