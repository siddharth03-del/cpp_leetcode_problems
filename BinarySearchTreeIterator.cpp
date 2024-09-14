#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator{
    public:
    vector<int> Tree;
    int index;
    BSTIterator(TreeNode* root){
        Tree = {};
        f(root);
        index = 0;
    }
    int next(){
        int temp = Tree[index];
        index++;
        return temp;
    }
    bool hasNext(){
        if(index != Tree.size()){
            return true;
        }else{
            return false;
        }
    }
    void f(TreeNode* root){
        if(root == nullptr){
            return;
        }
        f(root->left);
        Tree.push_back(root->val);
        f(root->right);
        return;
    }
};