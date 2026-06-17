#include <iostream>
using namespace std;

// Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2
// Output: 9->1->5->9->10->1

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 void insertAtEnd(ListNode **head,int value){
        ListNode *ptr= new ListNode(value);

        if((*head) == nullptr){
            (*head)=ptr;
            return;
        }

        ListNode *temp=(*head);
        while(temp->next != nullptr){
        temp=temp->next;
        }

        temp->next=ptr;
    }

void show(ListNode *head){
    ListNode *ptr=head;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}

ListNode* deleteMN(ListNode* head,int m,int n){
    if(head == nullptr){
        return nullptr;
    }
    if(m == 0){
        while(head){
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        return nullptr;
    }
    ListNode *ptr=head;
    while(ptr != nullptr){
        for(int i=0;i<m-1 && ptr;i++){
            ptr=ptr->next;    
        }
        if(ptr == nullptr) break;
        
        ListNode* ptr2=ptr->next;
        for(int i=0;i<n && ptr2;i++){
            ListNode* temp=ptr2;
            ptr2=ptr2->next;
            delete temp;
        }
        ptr->next=ptr2;
        ptr=ptr2;
    }
    return head;
}

int main() {
    ListNode *head=nullptr;

   insertAtEnd(&head,9);
   insertAtEnd(&head,1);
   insertAtEnd(&head,3);
   insertAtEnd(&head,5);
   insertAtEnd(&head,9);
   insertAtEnd(&head,4);
   insertAtEnd(&head,10);
   insertAtEnd(&head,1);

   show(head);
   cout<<endl;
   head=deleteMN(head,2,1);
   show(head);
    
    return 0;
}