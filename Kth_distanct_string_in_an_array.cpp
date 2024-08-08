#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    string kthDistinct(vector<string>& arr, int k){
        unordered_map<string, int> frequnecy;
        for(int i = 0; i < arr.size(); i++){
            if(frequnecy[arr[i]]){
                frequnecy[arr[i]]++;
            }
            else{
                frequnecy[arr[i]] = 1;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            if(frequnecy[arr[i]] == 1){
                if(k == 1){
                    return arr[i];
                }
                else{
                    k--;
                }
            }
        }
        return "";
    }
};