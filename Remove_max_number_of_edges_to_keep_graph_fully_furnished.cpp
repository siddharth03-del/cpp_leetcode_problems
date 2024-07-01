#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    void UNION(int x, int y, vector<int>& parent, vector<int>& size){
    int rootx = find(x, parent);
    int rooty = find(y, parent);
    int sizex = size[rootx];
    int sizey = size[rooty];
    if(sizex > sizey){
        parent[rooty] = rootx;
        size[rootx] += size[rooty];
    }
    else{
        parent[rootx] = rooty;
        size[rooty] += size[rootx];
    }
    }
    int find(int x, vector<int>& parent){
    if(parent[x] != x){
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges){
        int counter = 0;
        vector<int> aliceparent(n + 1);
        vector<int> bobparent(n + 1);
        vector<int> alicesize(n + 1, 1);
        vector<int> bobsize(n + 1, 1);
        for(int i = 1; i < n + 1; i++){
            aliceparent[i] = i;
            bobparent[i] = i;
        }
        for(int i = 0; i < edges.size() ; i++){
            if(edges[i][0] == 3){
                int aliceparent1 = find(edges[i][1], aliceparent);
                int aliceparent2 = find(edges[i][2], aliceparent);
                if(aliceparent1 != aliceparent2){
                    counter++;
                    UNION(edges[i][1], edges[i][2], aliceparent, alicesize);
                    UNION(edges[i][1], edges[i][2], bobparent, bobsize);
                }
            }
        }
        for(int i = 0 ; i < edges.size(); i++){
            if(edges[i][0] == 1){
                int parent1 = find(edges[i][1],aliceparent);
                int parent2 = find(edges[i][2], aliceparent);
                if(parent1 != parent2){
                    counter++;
                    UNION(edges[i][1], edges[i][2], aliceparent, alicesize);
                }
            }
            else if(edges[i][0] == 2){
                int parent1 = find(edges[i][1], bobparent);
                int parent2 = find(edges[i][2], bobparent);
                if(parent1 != parent2){
                    counter++;
                    UNION(edges[i][1], edges[i][2], bobparent, bobsize);
                }
            }
        }
        int parent1 = find(1, aliceparent);
        int parent2 = find(1, bobparent);
        int size1 = alicesize[parent1];
        int size2 = bobsize[parent2];
        if(size1 == n && size2 == n){
            return edges.size() - counter;
        }
        else{
            return -1;
        }
    }
};