#include <vector>
#include <queue>
using namespace std;
class SmallestInfiniteSet{
    public:
    vector<bool> present;
    priority_queue<int, vector<int>, greater<int>>q;
    SmallestInfiniteSet(){
        present.resize(1005, false);
        for(int i = 1; i < 1001; i++){
            q.push(i);
            present[i] = true;
        }
    }
    int popSmallest(){
        int r = q.top();
        q.pop();
        present[r] = false;
        return r;
    }
    void addBack(int num){
        if(!present[num]){
            present[num] = true;
            q.push(num);
        }
        return;
    }
};