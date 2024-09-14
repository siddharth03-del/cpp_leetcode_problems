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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        int i = 1;
        int j = 1;
        ListNode* curr = head;
        while(j - i != n){
            curr = curr->next;
            j++;
        }
        ListNode* iptr = head;
        while(curr != nullptr){
            curr = curr->next;
            iptr = iptr->next;
            i++;
            j++;
        }
        if(n == 1){
            iptr->next = nullptr;
            return head;
        }
        if(i == 1){
            ListNode* ans = head->next;
            head->next = nullptr;
            return ans;
        }
        else{
            ListNode* temp = iptr->next;
            iptr->next = iptr->next->next;
            temp->next = nullptr;
            return head;
        }
        return head;
    }
};