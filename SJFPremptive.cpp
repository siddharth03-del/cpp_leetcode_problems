#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Process {
public:
    string id;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int remaining;

    Process(string id, int arrival, int burst) {
        this->id = id;
        this->arrival = arrival;
        this->burst = burst;
        this->remaining = burst;
        this->waiting = 0;
        this->turnaround = 0;
    }
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; ++i) {
        string id;
        int arrival, burst;
        cout << "Enter process ID, arrival time, and burst time for process " << i + 1 << ": ";
        cin >> id >> arrival >> burst;
        processes.emplace_back(id, arrival, burst);
    }

    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int minRemaining = INT_MAX;
        int shortestIndex = -1;

        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival <= currentTime && processes[i].remaining > 0 && processes[i].remaining < minRemaining) {
                minRemaining = processes[i].remaining;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
            continue;
        }

        processes[shortestIndex].remaining--;
        currentTime++;

        if (processes[shortestIndex].remaining == 0) {
            completed++;
            processes[shortestIndex].turnaround = currentTime - processes[shortestIndex].arrival;
            processes[shortestIndex].waiting = processes[shortestIndex].turnaround - processes[shortestIndex].burst;
        }
    }

    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        cout << p.id << '\t' << p.arrival << '\t' << p.burst << '\t' << p.waiting << '\t' << p.turnaround << '\n';
    }

    return 0;
}
