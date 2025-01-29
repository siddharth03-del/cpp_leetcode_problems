#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution{
    public:
    vector<double> calcEquaations(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        unordered_map<string, unordered_map<string, double>>graph;
        for(int i = 0; i < equations.size(); i++){
            string x = equations[i][0];
            string y = equations[i][1];
            double val = values[i];
            graph[x][y] = val;
            graph[y][x] = 1/val;
        }
        vector<double> res;
        for(int i = 0; i < queries.size(); i++){
            double ans = dfs(graph, queries[i]);
            res.push_back(ans);
        }
        return res;
    }
    int dfs(unordered_map<string, unordered_map<string, double>>& graph, vector<string>& queries){
        unordered_map<string, double> visited;
        queue<string> q;
        string start = queries[0];
        string end = queries[1];
        visited[start] = 1;
        for(const auto& pair: graph[start]){
            visited[pair.first] = pair.second;
            q.push(pair.first);
        }
        while(!q.empty()){
            string point = q.front();
            q.pop();
            if(point == end){
                return visited[point];
            }
            else{
                for(const auto& pair: graph[point]){
                    if(visited.find(pair.first) == visited.end()){
                        visited[pair.first] = visited[point]*graph[point][pair.first];
                        q.push(pair.first);
                    }
                }
            }
        }
        return -1;
    }
};