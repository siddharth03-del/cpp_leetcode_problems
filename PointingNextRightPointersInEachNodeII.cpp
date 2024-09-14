#include <vector>
#include <deque>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution{
    public:
    Node* connect(Node* root){
        if(root == NULL)return NULL;
        deque<Node*> q;
        q.push_back(root);
        q.push_back(NULL);
        vector<vector<Node*>>nodes;
        vector<Node*> store;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop_front();
            if(temp == NULL){
                if(q.empty()){
                    break;
                }else{
                    q.push_back(NULL);
                    nodes.push_back(store);
                    store.clear();
                }
            }else{
                Node* left = temp->left;
                Node* right = temp->right;
                if(left){
                    store.push_back(left);
                    q.push_back(left);
                }
                if(right){
                    store.push_back(right);
                    q.push_back(right);
                }
            }
        }
        for(int i = 0; i < nodes.size(); i++){
            for(int j = 0; j < nodes[i].size(); j++){
                if(j < nodes[i].size()-1){
                    nodes[i][j]->next = nodes[i][j+1];
                }
        }
        }
        return root;
    }
};