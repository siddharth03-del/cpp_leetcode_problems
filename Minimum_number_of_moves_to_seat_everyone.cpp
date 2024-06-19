#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution{
public:
int minMovesToSeat(vector<int>& seats, vector<int>& students){
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int moves = 0;
    for(int i = 0; i < seats.size(); i++){
        int m = seats[i] - students[i];
        m = abs(m);
        moves += m;
    }
    return moves;
}
};