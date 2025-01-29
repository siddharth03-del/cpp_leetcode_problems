#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct comparator{
    bool operator()(vector<int> a, vector<int> b){
        if(a[0] < b[0]){
            return true;
        }
        else if(a[0] > b[0]){
            return true;
        }
        else{
            return a[1] < b[1];
        }
    }
};
class Solution{
    public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k){
        priority_queue<vector<int>, vector<vector<int>> , comparator> heap;
        queue<vector<int>>q;
        for(int i = 0; i < nums1.size(); i++){
            heap.push({nums1[i], nums2[i]});
        }
        long long sum = 0;
        int min = __INT_MAX__;
        for(int i = 0; i < k; i++){
            vector<int> temp = heap.top();
            q.push(temp);
            heap.pop();
            sum += temp[0];
            min = min < temp[1] ? min : temp[1];
        }
        long long ans = 0;
        while(heap.size() >= k){
            vector<int> top = q.front();
            q.pop();
            if(sum*min > ans){
                ans = sum*min;
            }
            vector<int> temp = heap.top();
            heap.pop();
            sum = sum - top[0] + temp[0];
            min = min < temp[1] ? min : temp[1];
        }
        return ans;
    }
};