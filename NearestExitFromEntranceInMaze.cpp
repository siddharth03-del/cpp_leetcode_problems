#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> neighbour = {{1,0},{0,1},{-1,0},{0, -1}};
        int exit = __INT_MAX__;
        bool found = false;
        queue<vector<int>> q;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        q.push(entrance);
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int x = cur[0];
            int y = cur[1];
            for(int i = 0; i < neighbour.size(); i++){
                int nx = x + neighbour[i][0];
                int ny = y + neighbour[i][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if(maze[nx][ny] == '.'){
                        cout << nx << " " << ny << endl;
                        if(nx == entrance[0] && ny == entrance[1]){
                            continue;
                        }
                        if(isExit(nx, ny, m, n)){
                            found = true;
                            exit = min(exit, distance[x][y] + 1);
                            distance[nx][ny] = distance[x][y] + 1;
                        }
                        else{
                            distance[nx][ny] = distance[x][y] + 1;
                            if(!visited[nx][ny]){
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        if(found){
            return exit;
        }
        else{
            return -1;
        }
    }
    bool isExit(int row, int col, int m, int n){
        if(row == 0 || col == 0 || row == m-1 || col == n-1){
            return true;
        }
        else{
            return false;
        }
    }
};