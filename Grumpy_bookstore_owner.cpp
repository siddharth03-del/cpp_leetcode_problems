#include <iostream>
#include <vector>
using namespace std;
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes){
    int increment = 0;
    int totalsatisfied = 0;
    int start = 0;
    int end = 0;
    int previousincrement;
    for(int i = 0; i < minutes; i++){
        if(grumpy[i] == 0){
            totalsatisfied += customers[i];
        }
        else{
            increment += customers[i];
        }
        end++;
    }
    previousincrement = increment;
    while(end < grumpy.size()){
        if(grumpy[end] == 0){
            totalsatisfied += customers[end];
        }
        if(grumpy[end] == 1){
            previousincrement = previousincrement + customers[end];
        }
        if(grumpy[start] == 1){
            previousincrement = previousincrement - customers[start];
        }
        if(previousincrement > increment){
            increment = previousincrement;
        }
        start++;
        end++;
    }
    return increment + totalsatisfied;
}
int main(){
    vector<int> c = {1,0,1,2,1,1,7,5};
    vector<int> g = {0,1,0,1,0,1,0,1};
    cout << maxSatisfied(c, g, 3);
    return 0;
}