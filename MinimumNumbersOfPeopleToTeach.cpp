#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships){
        int min = __INT_MAX__;
        for(int i = 1; i <= n; i++){
            int r = toTeach(i, languages, friendships);
            if(r < min) min = r;
        }
        return min;
    };
    int toTeach(int language, vector<vector<int>>& languages, vector<vector<int>>& friendships){
        int cnt = 0;
        unordered_map<int, bool>taught;
        for(int i = 0; i < friendships.size(); i++){
            int friend1 = friendships[i][0];
            int friend2 = friendships[i][1];
            vector<int> langfriend1 = languages[friend1-1];
            vector<int> langfriend2 = languages[friend2-1];
            if(!taught[friend1]){
                bool flag = true;
                for(int j = 0; j < langfriend1.size(); j++){
                    if(langfriend1[j] == language){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cnt++;
                }
                taught[friend1] = true;
            }
            if(!taught[friend2]){
                bool flag = true;
                for(int j = 0; j < langfriend2.size(); j++){
                    if(langfriend2[j] == language){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cnt++;
                }
                taught[friend2] = true;
            }
        }
        return cnt;
    }
};