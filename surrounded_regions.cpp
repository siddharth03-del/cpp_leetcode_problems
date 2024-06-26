#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> neighbours = {{-1,0}, {0,-1},{1,0},{0,1}};
void bfs(vector<vector<char>>& graph){
    queue<vector<int>> q;
    int n = graph.size();
    int m = graph[0].size();
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[0].size(); j++){
            if(i == 0 || i == graph.size()-1){
                if(graph[i][j] == 'O'){
                    q.push({i,j});
                    graph[i][j] = 'a';
                }
            }
            else if(j == 0 || j == graph[0].size()-1){
                if(graph[i][j] == 'O'){
                    q.push({i,j});
                    graph[i][j] = 'a';
                }
            }
        }
    }
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
               if(graph[nx][ny] == '0'){
                q.push({nx,ny});
                graph[nx][ny] = 'a';
               }
            }
        }
    }
}
void solve(vector<vector<char>>& board){
    bfs(board);
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            else if(board[i][j] == 'a'){
                board[i][j] = 'O';
            }
        }
    }
    return;
}