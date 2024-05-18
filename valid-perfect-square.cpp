#include <iostream>
#include <cmath>
using namespace std;
bool isPerfectSquare(int num){
    int low = 1;
    int high = num;
    int mid;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(pow(num, 0.5) < mid){
            high = mid - 1;
        }
        else if(pow(num, 0.5) > mid){
            low = mid + 1;
        }
        else{
            return true;
        }
    }
    return false;
}
int main(){
    cout<<isPerfectSquare(16);
    return 0;
}