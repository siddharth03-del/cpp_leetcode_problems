#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution{
    public:
    int getWinner(vector<int>& arr, int k){
        if(k >= arr.size()){
            int max = arr[0];
            for(int i = 1; i < arr.size(); i++){
                if(arr[i] > max){
                    max = arr[i];
                }
            }
            return max;
        }
        deque<int> dq;
        for(int i = 0; i < arr.size(); i++){
            dq.push_back(arr[i]);
        }
        int win = 0;
        while(win < k){
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if(a > b){
                dq.push_back(b);
                dq.push_front(a);
                win++;
            }
            else{
                dq.push_back(a);
                dq.push_front(b);
                win = 1;
            }
        }
        return dq.front();
    }
};