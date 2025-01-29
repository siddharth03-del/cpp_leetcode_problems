#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class SubrectangleQueries {
public:
    vector<vector<int>> values;
    vector<vector<int>> update;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        values = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vector<int> temp = { row1, col1, row2, col2, newValue};
        update.push_back(temp);
    }
    
    int getValue(int row, int col) {
        for(int i = update.size(); i >= 0; i--){
            int row1 = update[i][0];
            int col1 = update[i][1];
            int row2 = update[i][2];
            int col2 = update[i][3];
            int newValue = update[i][4];
            if(row >= row1 && row <= row2 && col >= col1 && col <= col){
                return newValue;
            }
        }
        return values[row][col];
    }
};