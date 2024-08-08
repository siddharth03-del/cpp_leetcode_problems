#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> graph;
    int glo;
    vector<int> ans;
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        graph.resize(n + 1, vector<int>(n + 1, -1));
        glo = n;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u][v] = graph[v][u] = 1;
        }
        int newtime = time;
        int n = time/change;
        bool signal;
        if(n == 1){
            signal = false;
        }
        else{
            signal = true;
        }
        traverse({1},time, change, signal, 1, newtime);
        sort(ans.begin(), ans.end());
        return ans[1];
    }
    void traverse(vector<int> visited, int time, int change, bool signal, int source, int currentime)
    {
        if (source == glo)
        {
            ans.push_back(currentime);
            return;
        }
        for (int i = 0; i < graph[source].size(); i++)
        {
            if (graph[source][i] == 1)
            {
                bool notvisited = true;
                for (int j = 0; j < visited.size(); j++)
                {
                    if (visited[j] == i)
                    {
                        notvisited = false;
                    }
                }
                if (notvisited)
                {
                    int newtime = currentime + time;
                    int n = currentime / change;
                    int a = newtime / change;
                    if (signal)
                    {
                        if (n == a && a != 0)
                        {
                            visited.push_back(i);
                            traverse(visited, time, change, true, i, newtime);
                        }
                        else
                        {
                            if (n != a || a == 0)
                            {
                                visited.push_back(i);
                                traverse(visited, time, change, false, i, newtime);
                            }
                        }
                    }
                    else
                    {
                        int r = currentime / change;
                        int waittime = (r + 1) * time - currentime;
                        visited.push_back(i);
                        traverse(visited, time, change, true, i, currentime + waittime + time);
                    }
                }
            }
        }
    }
};