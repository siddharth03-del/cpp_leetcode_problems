#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> tonodeglo;
    vector<int> toposort(vector<vector<int>>& graph, int n){
        vector<int> indegree(n, 0);
        vector<vector<int>> tonode(n, vector<int>());
        vector<vector<int>> fromnode(n, vector<int>());
        vector<int> topo;
        for(int i = 0; i < graph.size(); i++){
            int from = graph[i][0];
            int to = graph[i][1];
            indegree[to]++;
            tonode[to].push_back(from);
            fromnode[from].push_back(to);
        }
    tonodeglo = tonode;
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        topo.push_back(cur);
        q.pop();
        vector<int> temp = fromnode[cur];
        for(int i = 0; i < temp.size(); i++){
            indegree[temp[i]]--;
            if(indegree[temp[i]] == 0){
                q.push(temp[i]);
            }
        }
    }
    return topo;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges){
        vector<vector<int>> ans(n, vector<int>());
        vector<int> topo = toposort(edges, n);
        for(int i = 0; i < topo.size(); i++){
            vector<int> temp;
            queue<int> q;
            int curr = topo[i];
            for(int j = 0; j < tonodeglo[curr].size(); j++){
                q.push(tonodeglo[curr][j]);
                temp.push_back(tonodeglo[curr][j]);
            }
            while(!q.empty()){
            int cur = q.front();
            q.pop();
            vector<int> fill = ans[cur];
            for(int j = 0; j < fill.size(); j++){
                bool insert = true;
                for(int k = 0; k < temp.size(); k++){
                    if(fill[j] == temp[k]){
                        insert = false;
                    }
                }
                if(insert){
                    temp.push_back(fill[j]);
                }
            }
            }
            sort(temp.begin(), temp.end());
            ans[topo[i]] = temp;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> inp = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}}; 
    vector<vector<int>> ans = s.getAncestors(8, inp);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}