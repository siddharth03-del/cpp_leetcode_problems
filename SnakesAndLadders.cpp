#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution{
    public:
    int snakesAndLadders(vector<vector<int>>& board){
        return bfs(board);
    }
    int bfs(vector<vector<int>>& board){
        int n = board.size();
        queue<int>q;
        vector<int>visited(n*n + 2, 0);
        q.push(1);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n*n){
                return visited[curr];
            }
            for(int i = 1; i < 7; i++){
                int dest = curr + i;
                if(dest > n*n) break;
                int x = dest-1/n;
                int y = (dest-1)%n;
                if(x%2 == 0) y = n-1-y;
                else y = n-y;
                if(board[x][y] != -1){
                    q.push(board[x][y]);
                    visited[board[x][y]] = visited[curr] + 1;
                } 
                else{
                    q.push(dest);
                    visited[dest] = visited[curr] + 1;
                }
                if(!visited[curr]){
                    visited[curr] = true;
                }
            }
        }
        return -1;
    }
};