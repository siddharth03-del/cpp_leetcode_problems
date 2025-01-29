#include <vector>
using namespace std;
struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<ListNode*> ll;
        while(temp != nullptr){
            ListNode* n = temp->next;
            temp->next = nullptr;
            ll.push_back(temp);
            temp = n;
        }
        int a = 0;
        int b = ll.size() - 1;
        ListNode* hh =  new ListNode();
        ListNode* curr = hh;
        while(a < b){
            curr->next = ll[a];
            curr = curr->next;
            curr->next = ll[b];
            curr = curr->next;
            a++;
            b--;
        }
        if(a == b){
            curr->next = ll[a];
        }
        hh->next = nullptr;
        return;
    }
};