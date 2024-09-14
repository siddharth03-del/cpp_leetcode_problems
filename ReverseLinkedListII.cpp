#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution{
    public:
    ListNode* reverseBetween(ListNode* head, int left, int right ){
        
        vector<ListNode*> node;
        ListNode* curr = head;
        while(curr != nullptr){
            node.push_back(curr);
            ListNode* temp = curr->next;
            curr->next = nullptr;
            curr = temp;
        }
        ListNode* temp = node[left - 1];
        node[left - 1] = node[right - 1];
        node[right - 1] = temp;
        ListNode* curr = node[0];
        for(int i = 1; i < node.size(); i++){
            curr->next = node[i];
            curr = node[i];
        }
        curr->next = nullptr;
        return node[0];
    }
};