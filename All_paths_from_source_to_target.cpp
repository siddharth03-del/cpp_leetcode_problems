#include <vector>
using namespace std;
vector<vector<int>> result;
vector<vector<int>> gra;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        gra = graph;
        for(int i = 0 ; i < gra[0].size(); i++){
            vector<int> copy;
            copy.push_back(0);
            copy.push_back(gra[0][i]);
            func(copy);
        }
        return result;
    }
void func(vector<int>& inp){
    int point = inp[inp.size() - 1];
    if(point == gra.size() - 1){
        result.push_back(inp);
    }
    for(int i = 0; i < gra[point].size(); i++){
        vector<int> copy = inp;
        int check = gra[point][i];
        bool flag = true;
        for(int j = 0 ; j < inp.size(); j++){
            if(check == inp[j]){
                flag = false;
            }
        }
        if(flag){
            copy.push_back(gra[point][i]);
            func(copy);
        }
    }
    return;
}
int main(){
    vector<vector<int>> g = {{4,3,1},{3,2,4},{3},{4},{}};
    allPathsSourceTarget(g);
    return 0;
}