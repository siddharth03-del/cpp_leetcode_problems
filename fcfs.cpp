#include <queue>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Process{
    public:
    string id;
    int arrival;
    int bust;
};
class Compare{
    public:
    bool operator()(Process a, Process b){
        return a.arrival > b.arrival;
    }
};
void fcfs(priority_queue<Process, vector<Process>, Compare>& pros){
    int current_time = 0;
    cout << "Process" << " ";
    cout << "Arrival Time" << " ";
    cout << "Burst time" << " ";
    cout << "Waiting time" << " ";
    cout << "Turn arround time" << " ";
    cout << endl;
    while(!pros.empty()){
        Process p = pros.top();
        pros.pop();
        int arrival_time = p.arrival;
        int bust_time = p.bust;
        cout << p.id << " ";
        cout << arrival_time << " ";
        cout << bust_time << " ";
        if(arrival_time > current_time){
            cout << "0" << " ";
            current_time = arrival_time;
        }else{
            cout << current_time << " " ;
        }
        current_time = current_time + bust_time;
        cout << current_time << " ";
        cout << endl;
    }
}
int main(){
    int n;
    priority_queue<Process, vector<Process>, Compare> process; 
    cout << "enter the number of process" << endl;
    cin >> n;
    for(int i = 1; i <= n; i++){
        Process p;
        p.id = "p" + to_string(i);
        cout << "Enter Arrival and Burst for" << p.id << " ";
        cin >> p.arrival >> p.bust ;
        process.push(p);
    }
    cout << endl;
    fcfs(process);
    return 0;
}