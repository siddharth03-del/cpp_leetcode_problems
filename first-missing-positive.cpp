#include <iostream>
using namespace std;
#include <vector>
int firstMissingPositive(vector<int>& nums){
    int counter = 1;
    int i = 0;
    int temp;
    int j = nums.size() - 1;
    while ( i<= j){
        if(nums[i] == counter){
            i++;
            counter++;
        }
        else if(nums[j]== counter){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
            counter++;
        }
        else{
            j--;
        }
    }
    while(i< nums.size()){
        if(nums[i]== counter){
            counter++;
            i++;
        }
        else{
            i++;
        }
    }
    if(nums[i]== counter || nums[j]==counter){
        counter++;
        return counter;
    }
    else{
        return counter;
    }
}
int main(){
    vector<int> nums = {1,5,2,3};
    cout<<firstMissingPositive(nums);
    return 0;
}