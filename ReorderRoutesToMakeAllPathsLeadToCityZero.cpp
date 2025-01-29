#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int count;
    unordered_map<int, bool>visited;
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_map<int, int>>graph;
        count = 0;
        for(int i = 0; i < connections.size(); i++){
            int from = connections[i][0];
            int to = connections[i][1];
            graph[from][to] = 1;
            graph[to][from] = 0;
        }
        f(0, graph);
        return count;
    }
    void f(int city, unordered_map<int, unordered_map<int, int>>& graph){
        unordered_map<int, int> connection = graph[city];
        for(const auto& pair : connection){
            int to = pair.first;
            int type = pair.second;
            if(!visited[to]){
                visited[to] = true;
                count = count + type;
                f(to, graph);
            }
        }
        return;
    }
};