#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    public:
    bool isEvenOddTree(TreeNode* root){
        queue<TreeNode*> nodes;
        vector<int> temp;
        vector<vector<int>> bfs;
        nodes.push(root);
        nodes.push(nullptr);
        while(!nodes.empty()){
            if(nodes.front() == nullptr){
                bfs.push_back(temp);
                temp.erase(temp.begin(), temp.end());
                nodes.pop();
                if(nodes.empty()){
                    break;
                }
                else{
                    nodes.push(nullptr);
                }
            }
            else{
                temp.push_back(nodes.front()->val);
                if(nodes.front()->left){
                    nodes.push(nodes.front()->left);
                }
                if(nodes.front()->right){
                    nodes.push(nodes.front()->right);
                }
                nodes.pop();
            }
        }
        for(int i = 0; i < bfs.size(); i++){
            if(i % 2 == 0){
                if(bfs[i].size() == 1){
                    if(bfs[i][0] % 2 == 0){
                        return false;
                    }
                }
                for(int j = 0; j < bfs[i].size()-1; j++){
                    if(bfs[i][j] < bfs[i][j+1] && bfs[i][j] % 2 != 0 && bfs[i][j+1] % 2 != 0){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                if(bfs[i].size() == 1){
                    if(bfs[i][0] % 2 != 0){
                        return false;
                    }
                }
                for(int j = 0; j < bfs[i].size()-1 ; j++){
                    if(bfs[i][j] > bfs[i][j+1] && bfs[i][j] % 2 == 0 && bfs[i][j+1] % 2 == 0){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};