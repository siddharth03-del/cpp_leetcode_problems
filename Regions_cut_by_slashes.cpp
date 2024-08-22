#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int regionsBySlashes(vector<string>& grid){
        int n = grid.size();
        int m = n + 1;
        vector<int>dsu((m*m));
        vector<int> childrens((m*m), 1);
        for(int i = 0; i < dsu.size(); i++){
            dsu[i] = i;
        }
        for(int i = 0; i < m; i++){
            if(i == 0 || i == m -1){
                    for(int j = 0; j < m; j++){
                        dsu[i*m + j] = 0;
                        childrens[i*m + j] = 0;
                        childrens[0]++;
                    }
            }
            else{
                dsu[i*m + 0] = 0;
                childrens[i*m + 0] = 0;
                childrens[0]++;
                dsu[i*m + m-1] = 0;
                childrens[i*m + m-1] = 0;
                childrens[0]++;
            }
        }
        int regions = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '\\'){
                    int point1 = i*m + j;
                    int point2 = (i+1)*m + (j+1);
                    int parent1 = dsu[point1];
                    int parent2 = dsu[point2];
                    if(parent1 != parent2){
                        if(childrens[parent1] < childrens[parent2]){
                            dsu[point1] = parent2;
                            childrens[parent2] += childrens[parent1];
                            childrens[parent1] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent1){
                                    dsu[i] = parent2;
                                }
                            }
                        }
                        else{
                            dsu[point2] = parent1;
                            childrens[parent1] += childrens[parent2];
                            childrens[parent2] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent2){
                                    dsu[i] = parent1;
                                }
                            }
                        }
                    }
                    else{
                        regions++;
                        if(childrens[parent1] < childrens[parent2]){
                            dsu[point1] = parent2;
                            childrens[parent2] += childrens[parent1];
                            childrens[parent1] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent1){
                                    dsu[i] = parent2;
                                }
                            }
                        }
                        else{
                            dsu[point2] = parent1;
                            childrens[parent1] += childrens[parent2];
                            childrens[parent2] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent2){
                                    dsu[i] = parent1;
                                }
                            }
                        }
                    }
                }
                else if(grid[i][j] == '/'){
                    int point1 = (i+1)*m + j;
                    int point2 = i*m + j+1;
                    int parent1 = dsu[point1];
                    int parent2 = dsu[point2];
                    if(parent1 != parent2){
                        if(childrens[parent1] < childrens[parent2]){
                            dsu[point1] = parent2;
                            childrens[parent2] += childrens[parent1];
                            childrens[parent1] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent1){
                                    dsu[i] = parent2;
                                }
                            }
                        }
                        else{
                            dsu[point2] = parent1;
                            childrens[parent1] += childrens[parent2];
                            childrens[parent2] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent2){
                                    dsu[i] = parent1;
                                }
                            }
                        }
                    }
                    else{
                        regions++;
                        if(childrens[parent1] < childrens[parent2]){
                            dsu[point1] = parent2;
                            childrens[parent2] += childrens[parent1];
                            childrens[parent1] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent1){
                                    dsu[i] = parent2;
                                }
                            }
                        }
                        else{
                            dsu[point2] = parent1;
                            childrens[parent1] += childrens[parent2];
                            childrens[parent2] = 0;
                            for(int i = 0; i < dsu.size(); i++){
                                if(dsu[i] == parent2){
                                    dsu[i] = parent1;
                                }
                            }
                        }
                    }
                }
                else{
                    continue;
                }
            }
        }
        return regions;
    }
};