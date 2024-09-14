#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
class Compare{
    public:
    bool operator()(vector<int>a, vector<int>b){
        a[0] + a[1] > b[0] + b[1];
    }
};
class Solution{
    public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k){
        set<vector<int>> visited;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<vector<int>> ans;
        pq.push({num1[0], num2[0]});
        int i = 0;
        int j = 0;
        while(k > 0 && !pq.empty()){
            vector<int> top = pq.top();
            pq.pop();
            if(visited.find(top) == visited.end()){
                ans.push_back(top);
            }
            if(j + 1 < num2.size()){
                pq.push({num1[i], num2[j + 1]});
            }
        }
    }
};
