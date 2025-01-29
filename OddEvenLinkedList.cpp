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
    ListNode* oddEvenList(ListNode* head){
        if(head == NULL){
            return nullptr;
        }
        ListNode* oddhead = new ListNode();
        ListNode* evenhead = new ListNode();
        ListNode* oddcurr = oddhead;
        ListNode* evencurr = evenhead;
        ListNode* curr = head;
        bool flag = true;
        while(curr != nullptr){
            if(flag){
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = nullptr;
                oddcurr->next = temp;
                oddcurr = oddcurr->next;
                flag = false;
            }
            else{
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = nullptr;
                evencurr->next = temp;
                evencurr = evencurr->next;
                flag = true;
            }
        }
        oddhead = oddhead->next;
        evenhead = evenhead->next;
        oddcurr->next = evenhead;
        return oddhead;
    }
};