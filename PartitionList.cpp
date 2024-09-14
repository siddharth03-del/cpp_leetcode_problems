#include <iostream>
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
    ListNode* partition(ListNode* head, int x){
        if(head == NULL){
            return NULL;
        }
        ListNode* leasthead = new ListNode();
        ListNode* greaterhead = new ListNode();
        ListNode* leastcurr = leasthead;
        ListNode* greatercurr = greaterhead;
        ListNode* curr = head;
        while(curr != nullptr){
            if(curr->val < x){
                ListNode* temp = curr->next;
                curr->next = nullptr;
                leastcurr->next = curr;
                curr = temp;
            }else{
                ListNode* temp = curr->next;
                curr->next = nullptr;
                greatercurr->next = curr;
                curr = temp;
            }
        }
        ListNode* temp1 = leasthead;
        ListNode* temp2 = greaterhead;
        leasthead->next = nullptr;
        greaterhead->next = nullptr;
        leasthead = temp1;
        greaterhead = temp2;
        leastcurr->next = greaterhead;
        return leasthead;
    }
};