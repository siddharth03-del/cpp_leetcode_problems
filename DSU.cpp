#include <iostream>
#include <vector>
using namespace std;
void UNION(int x, int y, vector<int> parent, vector<int> size){
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
    }
}
int find(int x, vector<int> parent){
    if(parent[x] == x){
        return x;
    }
    else{
        parent[x] = find(parent[x], parent);
    }
}