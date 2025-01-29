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
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<vector<TreeNode*>> levels;
        queue<TreeNode*> queue;
        vector<TreeNode*> temp;
        queue.push(root);
        queue.push(nullptr);
        while(!queue.empty()){
            if(queue.front() == nullptr){
                queue.pop();
                vector<TreeNode*> a = temp;
                levels.push_back(a);
                temp.clear();
                if(queue.empty()){
                    break;
                }else{
                    queue.push(nullptr);
                }
            }else{
                TreeNode* node = queue.front();
                if(node->left){
                    queue.push(node->left);
                }
                if(node->right){
                    queue.push(node->right);
                }
                temp.push_back(queue.front());
                queue.pop();
            }
        }
        for(int i = 0; i < levels.size(); i++){
            if(i % 2 != 0){
                int a = 0;
                int b = levels[i].size() - 1;
                while(a < b){
                    int value = levels[i][a]->val;
                    levels[i][a]->val = levels[i][b]->val;
                    levels[i][b]->val = value;
                    a++;
                    b--;
                }
            }
        }
        return root;
    }
};