#include <iostream>
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
    struct compare{
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        };
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        
        for(auto &head:lists){
            if(head != nullptr) pq.push(head);
        }
        
        ListNode *dummy=new ListNode(0);
        ListNode *last=dummy;
        
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            if(node->next != nullptr){
                pq.push(node->next);
            }
            last->next=node;
            last=node;
        }
        return dummy->next;
    }
};

int main() {
    
    return 0;
}