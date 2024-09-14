#include <deque>
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
    ListNode* rotateRight(ListNode* head, int k){
        deque<ListNode*> q;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = nullptr;
            q.push_back(curr);
            curr = temp;
        }
        if(q.size() < k){
            k = q.size() % k;
        }
        for(int i = 0; i < k; i++){
            ListNode* temp = q.back();
            q.pop_back();
            q.push_front(temp);
        }
        ListNode* h = new ListNode();
        ListNode* curr2 = h;
        while(!q.empty()){
            ListNode* temp = q.front();
            q.pop_front();
            curr2->next = temp;
            curr2 = curr2->next;
        }
        ListNode* ans = h->next;
        h->next = nullptr;
        return ans;
    }
};