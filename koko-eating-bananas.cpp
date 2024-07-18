#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h){
    int max = piles[0];
    for(int j=0; j<piles.size(); j++){
        if(max < piles[j]){
            max = piles[j];
        }
    }
    int min = 0;
    int mid;
    int eatinghours=0;
    int k;
    while(min <= max){
        mid = (max-min)/2 + min;
        for(int i=0; i<piles.size(); i++){
            double num1 = piles[i];
            double num2 = mid;
            double temp = ceil(num1/num2);
            eatinghours = temp + eatinghours;
        }
        if(eatinghours <= h){
            k = mid;
            max = mid - 1;
        }
        else if(eatinghours > h){
            min = mid + 1;
        }
        eatinghours = 0;

    }
    return k;
}
int main(){
    vector<int> piles = {30,11,23,4,20};
    cout<<minEatingSpeed(piles, 5);
    return 0;
}