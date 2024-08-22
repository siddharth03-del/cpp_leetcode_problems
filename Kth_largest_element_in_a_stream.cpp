#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class KthLargest{
    public:
    int K;
    int Kthvalue;
    vector<int> num;
    bool kthdefined = false;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums){
        this->K = k;
        this->num = nums;
        for(int i =0; i < nums.size(); i++){
            minHeap.push(nums[i]);
        }
        if(minHeap.size() > k){
            for(int i = 0; i < minHeap.size() - k; i++){
                minHeap.pop();
            }
        }
    }
    int add(int val){
        int value;
        if(minHeap.size() < K){
            minHeap.push(val);
            value = minHeap.top();
        }
        else{
            if(val >= minHeap.top()){
                minHeap.pop();
                minHeap.push(val);
                value = minHeap.top();
            }
            else{
                value = minHeap.top();
            }
        }
        return value;
    }
};