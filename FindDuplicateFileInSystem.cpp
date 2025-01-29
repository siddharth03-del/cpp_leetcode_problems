#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    vector<vector<string>> findDuplicate(vector<string>& paths){
        unordered_map<string, vector<string>>map;
        for(int i = 0; i < paths.size(); i++){
            string file = paths[i];
            string root = "";
            int j = 0;
            cout << file << endl;
            while(file[j] != ' '){
                root += file[j];
                j++;
            }
            cout << root << endl;
            j++;
            while(j < file.size()){
                string dir = "";
                while(j < file.size() && file[j] != '('){
                    dir += file[j];
                    j++;
                }
                cout << dir << endl;
                j++;
                string content = "";
                while(j < file.size() && file[j] != ')'){
                    content += file[j];
                    j++;
                }
                cout << content << endl;
                map[content].push_back(root + "/" + dir);
                j++;
            }
        }
        vector<vector<string>>ans;
        for(const auto& it : map){
            if(it.second.size() > 1){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> path = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    s.findDuplicate(path);
}