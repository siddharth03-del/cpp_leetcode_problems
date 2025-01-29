#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Compare{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] > b[0];
    }
};
class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int i = 0; i < n; i++){
            freq[tasks[i]]++;
        }
        priority_queue<vector<int>, vector<vector<int>>, Compare>queue;
        for(const auto& a: tasks){
            
        }
    }
};