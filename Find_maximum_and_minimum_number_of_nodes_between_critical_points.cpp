#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> nodeBetweenCriticalPoints(ListNode* head){
        vector<int> maxima;
        vector<int> minima;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;
        int index = 1;
        int min = __INT_MAX__;
        while(nxt != nullptr){
            if(curr->val > prev->val && curr->val > nxt->val){
                maxima.push_back(index);
                if(minima.size() > 0){
                    if(index - minima.back() < min){
                        min = index - minima.back();
                    }
                }
            }
            if(curr->val < prev->val && curr->val < nxt->val){
                minima.push_back(index);
                if(maxima.size() > 0){
                    if(index - maxima.back() < min){
                        min = maxima.back() - index;
                    }
                }
            }
            index++;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        if(maxima.size() == 0 || minima.size() == 0){
            return {-1, -1};
        }
        int max = -1;
        if(abs(maxima[0] - minima.back()) >= abs(minima[0] - maxima.back())){
            max = abs(maxima[0] - minima.back());
        }
        else{
            max = minima[0] - maxima.back();
        }
        
    }
};