#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct CustomComparator{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]){
            return a[0] > b[0];
        }
        else{
            return a[1] > b[1];
        }
    }
};
class Solution{
    public:
    int maxEvents(vector<vector<int>>& events){
        sort(events.begin(), events.end(), CustomComparator());
        int occupied = events[0][0];
        int count = 1;
        for(int i = 1; i < events.size(); i++){
            if(events[i][0] > occupied){
                count++;
                occupied = events[i][0];
            }
            else{
                occupied++;
                if(events[i][1] >= occupied){
                    occupied = events[i][1];
                    count++;
                }
                else{
                    occupied--;
                }
            }
        }
        return count;
    }
};