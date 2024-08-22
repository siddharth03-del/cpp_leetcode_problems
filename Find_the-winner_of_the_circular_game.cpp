#include <queue>
#include <iostream>
using namespace std;
class Solution{
    queue<int> q;
    public:
    int findTheWinner(int n, int k){
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
    }
    int fun(int k){
        if(q.size() == 1){
            return q.back();
        }
        for(int i = 0; i < k-1; i++){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        q.pop();
        return fun(k);
    }
};