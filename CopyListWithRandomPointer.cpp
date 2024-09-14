#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution{
    public:
    Node* copyRandomList(Node* head){
        if(head == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> node;
        Node* curr = head;
        while(curr != NULL){
            int val = curr->val;
            Node* new_node = new Node(val);
            node[curr] = new_node;
            curr = curr->next;
        }
        Node* cur = head;
        while(cur != NULL){
            Node* nxt = cur->next;
            Node* random = cur->random;
            Node* key = node[cur];
            if(random == NULL){
                key->random = NULL;
            }else{
                key->random = node[random];
            }
            if(nxt == NULL){
                key->next = NULL;
            }else{
                key->next = node[nxt];
            }
        }
        return node[head];
    }
};