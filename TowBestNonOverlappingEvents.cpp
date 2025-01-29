#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct CustomComparator {
    bool operator()(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
};
bool compare(vector<int>&a, vector<int>& b){
    return a[0] > b[0];
}
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);
        int n = events.size();
        priority_queue<vector<int>, vector<vector<int>>, CustomComparator> maxheap;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp;
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];
            vector<vector<int>> store;
            while(!maxheap.empty()){
                if(maxheap.top()[1] < start){
                    temp = maxheap.top()[2] + value;
                    if(temp > ans){
                        ans = temp;
                    }
                    while(!store.empty()){
                        maxheap.push(store.back());
                        store.pop_back();
                    }
                    break;
                }
                else{
                    store.push_back(maxheap.top());
                    maxheap.pop();
                }
            }
            if(value > ans){
                ans = value;
            }
            maxheap.push(events[i]);
        }
        return ans;
    }
    
};