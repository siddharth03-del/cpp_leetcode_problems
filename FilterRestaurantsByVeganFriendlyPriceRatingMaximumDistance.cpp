#include <algorithm>
#include <vector>
using namespace std;
class custom{
    public:
    bool operator()(vector<int>a, vector<int>b){
        if(a[0] < b[0]){
            return true;
        }else if(a[0] > b[0]){
            return false;
        }else{
            return a[1] < b[1];
        }
    }
};
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> checker;
        for(int i = 0; i < restaurants.size(); i++){
            int vegan = restaurants[i][2];
            int price = restaurants[i][3];
            int distance = restaurants[i][4];
            if(vegan == veganFriendly){
                if(price <= maxPrice && distance <= maxDistance){
                    checker.push_back({restaurants[i][1], restaurants[i][0]}); //{rating, id}
                }
            }
        }
        sort(checker.begin(), checker.end(), custom());
        vector<int> ans;
        for(int i = 0; i < checker.size(); i++){
            ans.push_back(checker[i][1]);
        }
        return ans;
    }
};