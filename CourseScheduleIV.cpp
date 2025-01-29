#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses , vector<int>(numCourses, 0));
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
        }
        vector<bool> res(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            queue<int> check;
            for(int j = 0; j < numCourses; j++){
                if(graph[i][j] == 1) check.push(j);
            }
            while(!check.empty()){
                int node = check.front();
                check.pop();
                for(int j = 0; j < numCourses; j++){
                    if(graph[node][j] == 1){
                        if(graph[i][j] != 1){
                            check.push(j);
                            graph[i][j] = 1;
                        }
                    }

                }
            }
        }
        vector<bool> res;
        for(int i =0 ; i < queries.size(); i++){
            if(graph[queries[i][0]][queries[i][1]] == 1){
                res.push_back(true);
            }
        }
        return res;
    }   
};