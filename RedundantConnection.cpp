#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> visited(1001, 0);
        unordered_map<int, vector<int>>graph;
        for (int i = 0; i < edges.size(); i++){
            int from = edges[i][0];
            int to = edges[i][1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        unordered_map<int, bool> toRemove;
        queue<int> tobeVisited;
        tobeVisited.push(1);
        while (!tobeVisited.empty()) {
            int node = tobeVisited.front();
            tobeVisited.pop();
            if (visited[node]){
                toRemove[node] = true;
            }
            else{
                visited[node] = 1;
                for (int i = 0; i < graph[node].size(); i++){
                    tobeVisited.push(graph[node][i]);
                }
            }
        }
        for(int i = edges.size() - 1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(toRemove[u] && toRemove[v]){
                return edges[i];
            }
        }
        return {};
    }
};