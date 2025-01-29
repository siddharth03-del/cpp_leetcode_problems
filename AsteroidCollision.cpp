#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;
class Solution{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        deque<int> s;
        for(int i = 0; i < asteroids.size(); i++){
            int curr = asteroids[i];
            while(!s.empty() && s.back() > 0 && curr < 0){
                int temp = curr + s.back();
                if(temp < 0){
                    s.pop_back();
                    curr = curr;
                }
                else if(temp > 0){
                    curr = s.back();
                    s.pop_back();
                }
                else{
                    s.pop_back();
                    curr = 0;
                    break;
                }
            }
            if(curr == 0){
                continue;
            }
            else{
                s.push_back(curr);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.front());
            s.pop_front();
        }
        return ans;
    }
};