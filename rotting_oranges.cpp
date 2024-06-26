#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> neighbours = {{-1,0}, {0,-1},{1,0},{0,1}};
int bfs(vector<vector<int>>& grid){
    queue<vector<int>> q;
    int result = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                vector<int> curr = {i, j, 0};
                q.push(curr);
            }
        }
    }
    while(!q.empty()){
        vector<int> cur;
        cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int t = cur[2];
        for(int k = 0; k < 4; k++){
            int nx = x + neighbours[k][0];
            int ny = y + neighbours[k][1];
            if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
                continue;
            }
            else{
                if(grid[nx][ny] == 1){
                    q.push({nx, ny, t+1});
                    grid[nx][ny] = 2;
                    if(t+1 > result){
                        result = t + 1;
                    }
               }
            }
        }
    }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
    return result;
}
int orangesRotting(vector<vector<int>>& grid){
    return bfs(grid);
}
int main(){
    vector<vector<int>> inp = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(inp) << endl;
}