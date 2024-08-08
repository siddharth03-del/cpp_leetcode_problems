#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>> customer;
    double averageWaitingTime(vector<vector<int>>& customers){
        customer = customers;
        double ans = fun(0, 1);
        return ans/customers.size();
    }
    double fun(int index, int currentTime){
        if(index >= customer.size()){
            return 0;
        }
        int arrival = customer[index][0];
        int ordertime = customer[index][1];
        int waiting;
        if(currentTime <= arrival){
            waiting = ordertime;
            currentTime = arrival + ordertime;
        }
        else if(currentTime > arrival){
            waiting = currentTime - arrival + ordertime;
            currentTime += ordertime;
        }
        return waiting + fun(index + 1, currentTime);
    }
};