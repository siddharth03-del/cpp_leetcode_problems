#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string r = "";
        for(int i = 0; i < searchWord.size(); i++){
            vector<string> temp;
            r = r + searchWord[i];
            
        }
    }
};