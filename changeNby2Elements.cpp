#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int d):val(d),next(nullptr)
        {}
};

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

ListNode* change(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }

    ListNode* fast=head;
    ListNode* slow=head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
        
    }

    ListNode* second=reverse(slow->next);
    slow->next=second;

    ListNode* l1=head;
    ListNode* l2=second;

    while(l2 != nullptr){
        l1->val=l2->val-l1->val;
        l1=l1->next;
        l2=l2->next;
    }

    slow->next=reverse(second);
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Original List:\n";
    printList(head);

    head = change(head);

    cout << "Modified List:\n";
    printList(head);


    return 0;
}