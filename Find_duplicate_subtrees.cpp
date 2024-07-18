#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution{
    public:
    unordered_map<string, int> treevalue;
    struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    vector<TreeNode*> res;
    string fun(TreeNode* root){
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        string leftstring;
        string rightstring;
        if(left){
            leftstring = fun(left);
        }
        else{
            leftstring = "l";
        }
        if(right){
            rightstring = fun(right);
        }
        else{
            rightstring = "r";
        }
        string result = leftstring + to_string(root->val) + rightstring;
        if(treevalue[result] == 1){
            res.push_back(root);
        }
        else if(treevalue[result] == 0){
            treevalue[result] = 1;
        }
        return result;
    }
  vector<TreeNode*> findDuplicateSubTrees(TreeNode* root){
        fun(root);
        return res;
  }
};