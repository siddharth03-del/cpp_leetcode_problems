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
        else if(a.arrival == b.arrival){
            return a.burst > b.burst;
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
void sjfpremptive(priority_queue<Process, vector<Process>, Comparearrival>& arrival){
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
        cout << curr.burst << endl;
        if(curr.burst == 0){
            cout << curr.id << "     ";
            cout << curr.arrival << "    ";
            cout << curr.burst << "     ";
            cout << current_time - curr.arrival << "    ";
            cout << current_time - curr.arrival + curr.burst << "   ";
            burst.pop();
            curr = burst.top();
            cout << endl;
        }
        current_time = current_time + 1;
        curr.burst = curr.burst - 1;
        cout << "process done" << endl;
        cout << current_time << endl;
        while(!arrival.empty() && (arrival.top().arrival <= current_time)){
            burst.push(arrival.top());
            arrival.pop();
            cout << "new process added" << endl;
        }
    }
    return;
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
    sjfpremptive(arrival);
    return 0;
}