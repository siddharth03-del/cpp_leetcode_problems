#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int minMutation(string startGene, string endGene, vector<string>& bank){
        if(bank.size() < 1){
            return -1;
        }
        unordered_map<string, vector<string>>graph;
        int count1 = count(bank.begin(), bank.end(), startGene);
        if(count1 <= 0){
            bank.push_back(startGene);
        }
        for(int i = 0; i < bank.size(); i++){
            string root = bank[i];
            for(int j = 0; j < bank.size(); j++){
                int counter = 0;
                for(int k = 0; k < 8; k++){
                    if(root[k] != bank[j][k]){
                        counter++;
                    }
                }
                if(counter == 1){
                    graph[root].push_back(bank[j]);
                }
            }
        }
        return bfs(startGene, endGene, graph);
    }
    int bfs(string startGene, string endGene, unordered_map<string, vector<string>>& graph){
        queue<string> q;
        unordered_map<string , int> included;
        for(int i = 0; i < graph[startGene].size(); i++){
            included[graph[startGene][i]] = 1;
            q.push(graph[startGene][i]);
        }
        while(!q.empty()){
            string point = q.front();
            q.pop();
            if(point == endGene){
                return included[point];
            }
            for(int i = 0; i < graph[point].size(); i++){
                int distance = included[point] + 1;
                string dest = graph[point][i];
                if(included.find(dest) == included.end()){
                    included[dest] = distance;
                    q.push(dest);
                }
                else{
                    if(included[dest] > distance){
                        included[dest] = distance;
                    }
                }
            }
        }
        return -1;
    }
};