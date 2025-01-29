#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
    public:
    int lastStoneWeight(vector<int>& stones){
        priority_queue<int>maxheap;
        for(int i = 0; i < stones.size(); i++){
            maxheap.push(stones[i]);
        }
        while(maxheap.size() > 1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            if(x != y){
                maxheap.push(abs(x-y));
            }
        }
        if(maxheap.size() == 0){
            return 0;
        }
        return maxheap.top();
    }
};