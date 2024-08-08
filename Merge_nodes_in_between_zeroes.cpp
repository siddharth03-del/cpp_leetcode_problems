#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
    ListNode* mergeNodes(ListNode* head){
        vector<int> value;
        ListNode* current = head;
        int add = 0;
        bool addgoing = false;
        while(current != nullptr){
            if(current->val == 0){
                if(addgoing){
                    value.push_back(add);
                    addgoing = false;
                    add = 0;
                    current = current->next;
                }
                else{
                    addgoing = true;
                    current = current->next;
                }
            }
            else{
                if(addgoing){
                    add = add + current->val;
                    current = current->next;
                }
                else{
                    addgoing = true;
                    add = current->val;
                    current = current->next;
                }
            }
        }
        ListNode* newhead = new ListNode(value[0]);
        ListNode* current = newhead;
        for(int i = 1; i < value.size(); i++){
            ListNode* newnode = new ListNode(value[i]);
            current->next = newnode;
        }
        return newhead;
    }
};