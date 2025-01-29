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
    ListNode* deleteMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr){
            fast = fast->next;
            if(fast->next == nullptr){
                break;
            }
            fast = fast->next;
            if(fast->next != nullptr){
                slow = slow->next;
            }
        }
        if(fast == slow){
            return nullptr;
        }
        ListNode* temp = slow->next->next;
        slow->next = temp;
        return head;
    }
};