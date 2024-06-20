#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxDistance(vector<int>& position, int m){
    sort(position.begin(), position.end());
    int low = 0;
    int high = position[position.size() - 1] - position[0];
    int mid;
    int ans;
    while(low <= high){
        mid = (low + high) / 2;
        int ballsplaced = 1;
        int lastplaced = position[0];
        for(int i = 1; i < position.size(); i++){
            if(ballsplaced == m){
                break;
            }
            if(position[i] - lastplaced >= mid){
                lastplaced = position[i];
                ballsplaced++;
            }
        }
        if(ballsplaced == m){
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}