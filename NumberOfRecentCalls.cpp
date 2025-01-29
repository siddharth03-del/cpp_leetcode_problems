#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class RecentCounter{
    public:
    deque<int> d;
    RecentCounter(){
        
    }
    int ping(int t){
        d.push_back(t);
        vector<int> temp;
        int lower = t - 3000;
        int upper = t;
        int count = 0;
        while(d.size() > 0 && d.back() >= lower && d.back() <= upper){
            count++;
            temp.push_back(d.back());
            d.pop_back();
        }
        while(!temp.empty()){
            d.push_back(temp.back());
            temp.pop_back();
        }
        return count;
    }
};