#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> dp;
    vector<vector<int>> book;
    int widthmax;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth){
        dp.resize(1001, vector<int>(1001,-1));
        book = books;
        widthmax = shelfWidth;
        return fun(0, 0, shelfWidth);
    }
    int fun(int index, int height, int width_rem){
        if(dp[index][height] != -1){
            return dp[index][height];
        }
        if(index == book.size()){
            return height;
        }
        int width = book[index][0];
        int heighte = book[index][1];
        int a = fun(index + 1, heighte, widthmax-width) + height;
        int b = __INT_MAX__;
        if(width_rem >= width){
            b = fun(index + 1, max(height, heighte), width_rem - width);
        }
        return dp[index][height] = min(a,b);
    }
};