#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution{
    public:
    unordered_map<Node*, Node*>graph;
    Node* cloneGraph(Node* node){
        if(node == NULL){
            return nullptr;
        }
        graph[node] = new Node(node->val);
        vector<Node*> n = node->neighbors;
        for(int i = 0; i < n.size(); i++){
            bfs(n[i]);
        }
        for(const auto& pair: graph){
            vector<Node*> n = pair.first->neighbors;
            for(int i = 0; i < n.size(); i++){
                pair.second->neighbors.push_back(graph[n[i]]);
            }
        }
        return graph[node];
    }
    void bfs(Node* node){
        if(graph[node]){
            return;
        }
        graph[node] = new Node(node->val);
        vector<Node*> n = node->neighbors;
        for(int i = 0; i < n.size(); i++){
            bfs(n[i]);
        }
        return;
    }
};