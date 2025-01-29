#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<int>pile;
    int stoneGameII(vector<int>& piles){
        for(int i = 1; i < piles.size(); i++){
            piles[i] = piles[i] + piles[i-1];
        }
        pile = piles;
        
    }
    int f(int index, int M, bool chance){
        if(index >= pile.size()){
            return 0;
        }
        if(chance){
            
        }
    }
};
