#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int numRescueBoats(vector<int>& people, int limit){
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int boats = 0;
        while(j >= i){
            if(people[j] + people[i] <= limit){
                i++;
                j--;
                boats++;
            }else{
                j--;
                boats++;
            }
        }
        return boats;
    }
};