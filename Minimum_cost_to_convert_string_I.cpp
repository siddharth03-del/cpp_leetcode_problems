#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    vector<vector<int>> graph;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        graph.resize(28, vector<int>(28, -1));
        vector<vector<long long>> ansmatrix(27, vector<long long>(27, -1));
        for(int i = 0; i < original.size(); i++){
            int from = static_cast<int>(original[i]);
            int to = static_cast<int>(changed[i]);
            int weight = cost[i];
            from -= 97;
            to -= 97;
            if(graph[from][to] == -1){
                graph[from][to] = weight;
            }
            else{
                if(graph[from][to] > weight){
                    graph[from][to] = weight;
                }
            }
        }
        long long ans = 0l;
        for(int i = 0; i < source.size(); i++){
            char s = source[i];
            char t = target[i];
            int s1 = static_cast<int>(s);
            int t1 = static_cast<int>(t);
            long long r;
            if(ansmatrix[s1][t1] == -1){
                r = dijiktras(s1,t1);
                ansmatrix[s1][t1] = r;
            }
            else{
                r = ansmatrix[s1][t1];
            }
            if(r != -1l){
                ans += r;
            }
            else{
                return -1;
            }
        }
        return ans;
    }
    int dijiktras(int source, int target){
        vector<vector<int>> path(28,vector<int>());
        unordered_map<int, int> shortest;
        queue<int> tovisit;
        for(int i = 0; i < 26; i++){
            if(graph[source][i] == -1){
                shortest[i] = __INT_MAX__;
            }
            else{
                shortest[i] = graph[source][i];
                tovisit.push(i);
                path[i].push_back(source);
            }
        }
        while(!tovisit.empty()){
            int cur = tovisit.front();
            tovisit.pop();
            vector<int> visited = path[cur];
            int till = shortest[cur];
            for(int i = 0; i < 26; i++){
                if(graph[cur][i] != -1){
                    bool visit = true;
                    for(int j = 0; j < visited.size(); j++){
                        if(visited[j] == i){
                            visit = false;
                            break;
                        }
                    }
                    if(visit){
                        int w = graph[cur][i];
                        if(shortest[i] > till + w){
                            shortest[i] = till + w;
                            visited.push_back(i);
                            tovisit.push(i);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for(const auto& pair: shortest){
        if(pair.first == target){
            ans = pair.second;
            }
        }
        if(ans == 2147483647){
            ans = -1;
        }
        return ans;
    }
};

