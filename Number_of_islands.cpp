#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> neighbours = {{-1,0}, {0,-1},{1,0},{0,1}};
vector<vector<char>> glo;
void bfs(int i , int j){
    queue<vector<int>> q;
    int n = glo.size();
    int m = glo[0].size();
    q.push({i,j});
    glo[i][j] = '0';
    while(!q.empty()){
        vector<int> temp = q.front();
        q.pop();
        int x = temp[0];
        int y = temp[1];
        for(int k = 0; k < 4; k++){
            int nx = x + neighbours[k][0];
            int ny = y + neighbours[k][1];
            if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
                continue;
            }
            else{
                if(glo[nx][ny] == '1'){
                    glo[nx][ny] = '0';
                    q.push({nx,ny});
                }
            }
        }
    }
}
int maxAreaOfIsland(vector<vector<char>>& grid){
    int result = 0;
    glo = grid;
    for(int i = 0; i < glo.size(); i++){
        for(int j = 0; j < glo[0].size(); j++){
            if(glo[i][j] == '1'){
                bfs(i, j);
                result++;
        }
    }
    return result;
}