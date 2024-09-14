#include <unordered_map>
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
    ListNode* deleteDuplicates(ListNode* head){
        unordered_map<int, int>node;
        ListNode* curr = head;
        while(curr != nullptr){
            int val = curr->val;
            if(node[val]){
                node[val]++;
            }else{
                node[val] = 1;
            }
            curr = curr->next;
        }
        ListNode* h = new ListNode();
        ListNode* cur = h;
        curr = head;
        while(curr != nullptr){
            int val = curr->val;
            // cout << val << endl;
            // cout << node[val] << endl;
            if(node[val] == 1){
                ListNode* temp = curr;
                curr = curr->next;
                cur->next = temp;
                cur = cur->next;
                cur->next = nullptr;
            }else{
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = nullptr;
            }
        }
        ListNode* ans = h->next;
        h->next = nullptr;
        return ans;
    }
};