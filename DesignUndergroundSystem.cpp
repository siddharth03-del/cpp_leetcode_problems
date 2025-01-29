#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class UndergroundSystem {
public:
    unordered_map<int, unordered_map<string, double>>activeCheckin;
    unordered_map<string, unordered_map<string, double>>average;
    unordered_map<string, unordered_map<string, int>>count;
    UndergroundSystem() {
        activeCheckin.clear();
        average.clear();
        count.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        unordered_map<string, double> temp = activeCheckin[id];
        temp[stationName] = t;
        activeCheckin[id] = temp;
    }
    
    void checkOut(int id, string stationName, int t) {
        unordered_map<string, double>checkininfo = activeCheckin[id];
        activeCheckin.erase(id);
        string start;
        for(const auto& it: checkininfo){
            start = it.first;
        }
        string end = stationName;
        double time = t - checkininfo[start];
        double co = count[start][end];
        double sum = co * average[start][end];
        average[start][end] = double(sum + time) / double(co + 1);
        count[start][end] = co + 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return average[startStation][endStation];
    }
};