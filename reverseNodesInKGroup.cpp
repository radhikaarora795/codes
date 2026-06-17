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
    ListNode *reverse(ListNode* first, int n){
        if(first == nullptr) return nullptr;
        ListNode* prev=nullptr;
        ListNode* current = first;
        ListNode* after = current->next;
        for(int i=0;i<n;i++){
            after = current->next;
            current->next=prev;
            prev = current;
            current = after;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode *ptr=head;
        for(int i=0;i<k;i++){
            if(ptr == nullptr){
                return head;
            }
            ptr=ptr->next;
        }
        ListNode *newHead=reverse(head,k);
        head->next=reverseKGroup(ptr,k);
        return newHead;
    }
};

int main() {
    
    return 0;
}