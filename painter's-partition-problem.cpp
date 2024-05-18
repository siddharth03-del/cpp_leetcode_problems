#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int>& nums, int mid, int k, int B){
    if( nums.size() > k){
        k = nums.size();
    }
    int checker=0;
    int subarray=0;
    for(int i = 0; i < nums.size(); i++){
        checker = checker + nums[i]*B;
        if(checker > mid){
            subarray++;
            checker = nums[i]*B;
        }
    }
    subarray++;
    if(subarray <= k){
        return true;
    }
    else{
        return false;
    }
}
int paint(int A, int B, vector<int>& C){
    int answer = -1;
    int max = 0;
    int min = C[0];
    for(int i=0; i<C.size(); i++){
        max = max + C[i];
        if(min < C[i]){
            min = C[i];
        }
    }
    max = B*max;
    min = B*min;
    int mid;
    while(max >= min){
        mid = (max-min)/2 + min;
        if(isValid(C, mid, A, B)){
            answer = mid;
            max = mid-1;
        }
        else{
            min = mid + 1;
        }
    }
    return answer;
}
int main(){
    vector<int> C = {1,8,11,3};
    int A = 10;
    int B = 1;
    cout<<paint(A, B, C)<<endl;
    return 0;
}