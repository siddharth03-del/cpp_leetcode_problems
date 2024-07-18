#include <iostream>
#include <unordered_map>
#include <vector>
class Solution{
    public:
    Treenode* createBinaryTree(vector<vector<int>>& descriptions){
        unordered_map<int, TreeNode*> Tree;
        unordered_map<TreeNode*, int> child;
        TreeNode* result;
        for(int i = 0; i < descriptions.size(); i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            TreeNode* childnode;
            TreeNode* parentnode;
            if(Tree[child]){
                childnode = Tree[child];
            }
            else{
                childnode = new TreeNode(child);
                Tree[child] = childnode;
            }
            if(Tree[parent]){
                parentnode = Tree[parent];
            }
            else{
                parentnode = new TreeNode(parent);
                Tree[parent] = parentnode;
                child[parentnode] = 0;
            }
            if(isLeft){
                parentnode->left = childnode;
                if(child[childnode]){
                    child[childnode] = 1;
                }
            }
            else{
                parentnode->right = childnode;
                if(child[childnode]){
                    child[childnode] = 1;
                }
            }
        }
        for (const auto& kv : child) {
        if (kv.second == 0) {
            result = kv.first;
            }
        }
    return reuslt;
    }
}
