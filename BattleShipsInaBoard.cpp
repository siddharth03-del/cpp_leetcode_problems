#include <array>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> neighbours = {{1,0}, {0,1},{-1,0},{0,-1}};
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'X'){
                    count++;
                    remove(board, i, j);
                }
            }
        }
        return count;
    }
    void remove(vector<vector<char>>& board, int i, int j){
        queue<vector<int>>active;
        active.push({i, j});
        while(!active.empty()){
            vector<int> a = active.front();
            active.pop();
            board[a[0]][a[1]] = '.';
            for(int k = 0; k < neighbours.size(); k++){
                int x = a[0] + neighbours[k][0];
                int y = a[1] + neighbours[k][1];
                if( x >= 0 && x < board.size() && y >= 0 && y < board[0].size()){
                    if(board[x][y] == 'X'){
                        active.push({x, y});
                    }
                }
            }
        }
        return;
    }
};