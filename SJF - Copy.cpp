#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Process{
    public:
    string id;
    int arrival;
    int burst;
};
class Comparearrival{
    public:
    bool operator()(Process a, Process b){
        if(a.arrival > b.arrival){
            return true;
        }
        else{
            return false;
        }
    }
};
class CompareBurst{
    public:
    bool operator()(Process a, Process b){
        return a.burst > b.burst;
    }
};
void sjf(priority_queue<Process, vector<Process>, Comparearrival>& arrival){
    priority_queue<Process, vector<Process>, CompareBurst> burst;
    cout << "Process" << " ";
    cout << "Arrival Time" << " ";
    cout << "Burst time" << " ";
    cout << "Waiting time" << " ";
    cout << "Turn arround time" << " ";
    cout << endl;
    Process curr = arrival.top();
    arrival.pop();
    int current_time = curr.arrival;
    burst.push(curr);
    while(!burst.empty()){
        curr = burst.top();
        burst.pop();
        cout << curr.id << "    ";
        cout << curr.arrival << "   ";
        cout << curr.burst << "     ";
        int waiting_time = current_time - curr.arrival;
        cout << waiting_time << "     ";
        int turn_around_time = waiting_time + curr.burst;
        cout << turn_around_time;
        cout<<endl;
        current_time = curr.burst + current_time;
        if(!arrival.empty()){
            while(current_time >= arrival.top().arrival){
            burst.push(arrival.top());
            arrival.pop();
            if(arrival.empty()){
                break;
            }
            }
        }
    }
}
int main(){
    int n;
    priority_queue<Process, vector<Process>, Comparearrival> arrival;
    cout << "enter the number of process" << endl;
    cin >> n;
    for(int i = 1; i <= n; i++){
        Process p;
        p.id = "p" + to_string(i);
        cout << "Enter Arrival and Burst for" << p.id << " ";
        cin >> p.arrival >> p.burst ;
        arrival.push(p);
    }
    cout << endl;
    sjf(arrival);
    return 0;
}

