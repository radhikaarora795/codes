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
    ListNode* reverse(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* after=curr->next;

        while(curr != nullptr){
            after=curr->next;
            curr->next=prev;
            prev=curr;
            curr=after;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!= nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* ptr=reverse(slow);

        ListNode *l1=head;
        ListNode *l2=ptr;

        while(l2 != nullptr){
            if(l1->val != l2->val){
                return false;
            }
            l1=l1->next;
            l2=l2->next;
        }

        return true;

    }
};

int main() {
    
    return 0;
}