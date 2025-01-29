#include <queue>
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution{
    public:
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vector<int>province(n);
        unordered_map<int, int> psize;
        vector<int> total(n);
        for(int i = 0; i < n; i++){
            province[i] = i;
            psize[i] = 1;
            total[i] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int parent = province[i];
                int parent2 = province[j];
                if(i == j){
                    continue;
                }
                if(parent == parent2){
                    continue;
                }
                if(isConnected[i][j] == 1){
                    if(psize[parent] > psize[parent2]){
                        province[parent2] = parent;
                        total[parent2] = 0;
                        cout << parent2 << endl;
                        psize[parent] += psize[parent2];
                    }
                    else{
                        province[parent] = parent2;
                        total[parent] = 0;
                        cout << parent << endl;
                        psize[parent2] += psize[parent];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(total[i] == 1){
                ans++;
            }
        }
        return ans;
    }
};