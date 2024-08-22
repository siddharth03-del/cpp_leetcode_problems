#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    int nthUglyNumber(int n){
        if(n == 1){
            return 1;
        }
        priority_queue<int, vector<int>, greater<int>()> q;
        unordered_map<int, int> m;
        q.push(1);
        for(int i = 1; i < 1500; i++){
            q.push(i * 2);
            q.push(i * 3);
            q.push(i * 5);
        }
        int num;
        for(int i = 0; i < n; i++){
            num = q.top();
            q.pop();
        }
        return num;
    }
};