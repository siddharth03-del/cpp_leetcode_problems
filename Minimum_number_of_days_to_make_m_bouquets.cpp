#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minDays(vector<int>& bloomDay, int m, int k){
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int low = 1;
    int mid;
    int ans = -1;
    while(low <= high){
        mid = (low + high) / 2;
        int bouquets = 0;
        int flowers = 0;
        bool making_bouque = false;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bouquets == m){
                break;
            }
            if(bloomDay[i] <= mid){
                if(making_bouque){
                    flowers++;
                    if(flowers == k){
                        bouquets++;
                        flowers = 0;
                    }
                }
                else{
                    making_bouque = true;
                    flowers = 1;
                    if(flowers == k){
                        bouquets++;
                        flowers = 0;
                        making_bouque = false;
                    }
                }
            }
            else{
                if(making_bouque){
                    making_bouque = false;
                    flowers = 0;
                }
            }
        }
        if(bouquets == m){
            ans = mid;
            high = mid - 1;
            bouquets = 0;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}