#include <iostream>
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
    int maxLevelSum(TreeNode* root){
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> temp;
        while(!q.empty()){
            if(q.front() == nullptr){
                ans.push_back(temp);
                temp = {};
                q.pop();
                if(q.empty()){
                    break;
                }
                else{
                    q.push(nullptr);
                }
            }
            else{
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
        }
        int max = -__INT_MAX__;
        int maxLevel = 0;
        for(int i = 0; i < ans.size(); i++){
            int sum = 0;
            for(int j = 0; j < ans[i].size(); j++){
                sum += ans[i][j];
            }
            if(sum > max){
                max = sum;
                maxLevel = i;
            }
        }
        return maxLevel + 1;
    }
};