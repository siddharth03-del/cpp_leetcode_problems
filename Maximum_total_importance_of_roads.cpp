#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
    struct compare{
    bool operator()(vector<int>& lhs, vector<int>& rhs) const{
        return lhs[1] > rhs[1];
    }
    };
    public:
    long long maximumImportance(int n, vector<vector<int>>& roads){
        priority_queue< vector<int>, vector<vector<int>>, compare> lowestHeap;
        vector<int> values(n, 0);
        for(int i = 0; i < roads.size(); i++){
            vector<int> temp = roads[i];
            int a = temp[0];
            int b= temp[1];
            values[a]++;
            values[b]++;
        }
        for(int i = 0; i < n; i++){
            vector<int> temp = {i, values[i]};
            lowestHeap.push(temp);
        }
        values.clear();
        int assign = 1;
        while(!lowestHeap.empty()){
            vector<int> temp = lowestHeap.top();
            lowestHeap.pop();
            values[temp[0]] = assign;
            assign++;
        }
        long long maximumImportance = 0;
        for(int i =0 ; i < roads.size(); i++){
            int a = roads[i][0];
            int b = roads[i][1];
            maximumImportance += values[a] + values[b];
        }
    return maximumImportance;
    }
};