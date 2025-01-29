#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution{
    public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        set<int> visited;
        queue<int> tovisit;
        tovisit.push(0);
        while(!tovisit.empty()){
            int room = tovisit.front();
            tovisit.pop();
            if(visited.find(room) != visited.end()){
                continue;
            }
            else{
                visited.insert(room);
                for(int i = 0; i < rooms[room].size(); i++){
                    tovisit.push(rooms[room][i]);
                }
            }
        }
        for(int i = 0; i < rooms.size(); i++){
            if(visited.find(i) == visited.end()){
                return false;
            }
        }
        return true;
    }
};