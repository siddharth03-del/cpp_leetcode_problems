#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class SeatManager{
    public:
    priority_queue<int, vector<int>, greater<int>()>minheap;
    SeatManager(int n){
        for(int i = 1; i <= n; i++){
            minheap.push(i);
        }
    }
    int reserve(){
        int a = minheap.top();
        minheap.pop();
        return a;
    }
    void unreserve(int seatnumber){
        minheap.push(seatnumber);
    }
};