#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution{
    public:
    bool canMeasureWater(int x, int y, int target){
        vector<vector<int>>graph(x+1 , vector<int>(y+1, -1));
        queue<pair<int, int>>q;
        q.push({0,0});
        graph[0][0] = 1;
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if(a + b == target){
                return true;
            }
            if(a < x && graph[x][b] == -1){
                graph[x][b] = 1;
                q.push({x, b});
            }
            if(b < y && graph[a][y] == -1){
                graph[a][y] = 1;
                q.push({a, y});
            }
            if(a < x && a + b >= x && graph[x][a + b - x] == -1){
                graph[x][a + b - x] = 1;
                q.push({x, a + b - x});
            }
            if(b < y && a + b >= y && graph[a + b - y][y] == -1){
                graph[a + b - y][y] = 1;
                q.push({a + b - y, y});
            }
            if()
        }

    }
};