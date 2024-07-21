#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<int> toposort(vector<vector<int>>& dependencyarray, int k){
        vector<int> indegree(k+1, 0);
        vector<vector<int>> depend(k+1, vector<int>());
        for(int i = 0; i < dependencyarray.size(); i++){
            vector<int> arr = dependencyarray[i];
            int dependee = arr[0];
            int dependon = arr[1];
            indegree[dependee]++;
            depend[dependon].push_back(dependee);
        }
        queue<int> q;
        vector<int> result;
        for(int i = 1; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                indegree[i] = -1;
            }
        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i = 0; i < depend[cur].size(); i++){
                int dependee = depend[cur][i];
                indegree[dependee]--;
            }
            result.push_back(cur);
            for(int i = 1; i < indegree.size(); i++){
                if(indegree[i] == 0){
                    indegree[i] = -1;
                    q.push(i);
                }
            }
        }
        
        return result;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowfill = toposort(rowConditions, k);
        vector<int> colfill = toposort(colConditions, k);
        int count = k;

        reverse(rowfill.begin(), rowfill.end());
        reverse(colfill.begin(), colfill.end());
        bool fill = false;;
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        vector<vector<int>> res;
        
        for(int i = 0; i < rowfill.size(); i++){
            fill = false;
            for(int j = 0; j < colfill.size(); j++){
                if(rowfill[i] == colfill[j]){
                    int row = rowfill[i];
                    int col = colfill[j];
                    matrix[i][j] = row;
                    fill = true;
                    k--;
                    
                    break;
                }
            }
            if(!fill){
                return res;
            }
        }
        if(!fill){
            return res;
        }
        if(k != 0){
            return res;
        }
        return matrix;
    }
};