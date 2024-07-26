#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution{
    public:
    vector<vector<int>> matrix;
    int findCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        matrix.resize(n, vector<int>(n -1));
        for(int i = 0; i < edges.size(); i++){
            vector<int> vec = edges[i];
            int from = vec[0];
            int to = vec[1];
            int weight = vec[2];
            matrix[from][to] = weight;
            matrix[to][from] = weight;
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            int ans = dijiktras(n, i, distanceThreshold);
            res.push_back(ans);
        }
        int min = 0;
        for(int i = 0; i < res.size(); i++){
            if(res[i] <= res[min]){
                min = i;
            }
        }
        return min;
    }
    int dijiktras(int n, int node, int distance){
        vector<vector<int>> path(n,vector<int>());
        unordered_map<int, int> shortest;
        queue<int> tovisit;
        for(int i = 0; i < n; i++){
            if(matrix[node][i] == -1){
                shortest[i] = __INT_MAX__;
            }
            else{
                shortest[i] = matrix[node][i];
                tovisit.push(i);
                path[i].push_back(node);
            }
        }
        while(!tovisit.empty()){
            int cur = tovisit.front();
            tovisit.pop();
            vector<int> visited = path[cur];
            int till = shortest[cur];
            for(int i = 0; i < n; i++){
                if(matrix[cur][i] != -1){
                    bool visit = true;
                    for(int j = 0; j < visited.size(); j++){
                        if(visited[j] == i){
                            visit = false;
                            break;
                        }
                    }
                    if(visit){
                        int w = matrix[cur][i];
                        if(shortest[i] > till + w){
                            shortest[i] = till + w;
                            visited.push_back(i);
                            tovisit.push(i);
                        }
                    }
                }
            }
        }
        int count = 0;
        for(const auto& pair: shortest){
        if(pair.second <= distance){
            count++;
            }
        }
        return count;
    }
};
