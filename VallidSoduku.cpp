#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution{
    bool isValidSudoku(vector<vector<char>>& board){
        set<char> charset;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(charset.find(board[i][j]) != charset.end() ){
                        return false;
                    }else{
                        charset.insert(board[i][j]);
                    }
                }
            }
            charset.clear();
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(charset.find(board[j][i]) != charset.end() ){
                        return false;
                    }else{
                        charset.insert(board[j][i]);
                    }
                }
            }
            charset.clear();
        }
        vector<vector<int>> coordinates ={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(int i = 0; i < coordinates.size(); i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[x+i][y+j] != '.'){
                        if(charset.find(board[x+i][y+j]) != charset.end() ){
                            return false;
                        }
                        else{
                            charset.insert(board[x+i][y+j]);
                        }
                    }
                }
            }
            charset.clear();
        }
        return true;
    }
};