#include <vector>
#include <string>
using namespace std;
class Solution{
    public:
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool exist(vector<vector<char>>& board, string word){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                bool ans = f(board, word, i, j, 1, 0);
            }
        }
    }
    bool f(vector<vector<char>>& board, string word, int row, int col, int direction, int idx){
        if(idx >= word.size()){
            return true;
        }
        bool ans = false;
        if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size()){
            if(board[row][col] == word[idx]){
                for(int i = 0; i < directions.size(); i++){
                    if(i != direction){
                        int n = row + directions[i][0];
                        int m = col + directions[i][1];
                        ans = f(board, word, n, m, i, idx + 1);
                    }
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};