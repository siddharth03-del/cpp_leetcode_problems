#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> mostVisited(int n, vector<int>& rounds){
        vector<int>sectors(n+1, 0);
        for(int i = 0; i < rounds.size()-1; i++){
            int start = rounds[i];
            int end = rounds[i+1];
            int j = start;
            while(j != end){
                sectors[j]++;
                j = (j % n) + 1;
            }
        }
        int max = 0;
        for(int i = 0; i < sectors.size(); i++){
            if(sectors[i] > max){
                max = sectors[i];
            }
        }
        vector<int> ans;
        for(int i = 0; i < sectors.size(); i++){
            if(sectors[i] == max){
                ans.push_back(i);
            }
        }
    }
};