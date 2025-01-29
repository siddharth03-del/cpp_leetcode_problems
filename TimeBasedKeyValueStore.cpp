#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
class TimeMap {
public:
    unordered_map<string , map<int, string>>map;
    TimeMap() {
        map.clear();
    }
    
    void set(string key, string value, int timestamp) {
        vector<int , string>temp = 
        map[key].push_back(temp);
    }
    string get(string key, int timestamp) {
        vector<vector<int, string>> values = map[key];
        int left = 0;
        int right = values.size()-1;
        string ans;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(values[mid][0] < timestamp){
                left = mid+1;
                ans = values[mid][1];
            }
            else if(values[mid][0] > timestamp){
                right = mid-1;
            }
            else{
                ans = values[mid][0];
                break;
            }
        }
        
    }
};
