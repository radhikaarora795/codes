#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head == nullptr){
            return nullptr;
        }
        
        Node *zerodummy=new Node(-1);
        Node *onedummy=new Node(-1);
        Node *twodummy=new Node(-1);
        
        Node *zero=zerodummy;
        Node *one=onedummy;
        Node *two=twodummy;
        
        Node *ptr=head;
        
        while(ptr != nullptr){
            if(ptr->data == 0){
                zero->next=ptr;
                zero=zero->next;
            }
            else if(ptr->data == 1){
                one->next=ptr;
                one=one->next;
            }
            else if(ptr->data == 2){
                two->next=ptr;
                two=two->next;
            }
            ptr=ptr->next;
        }
        
        zero->next = (onedummy->next != nullptr)? onedummy->next: twodummy->next;
        one->next = twodummy->next;
        two->next = nullptr;
        
        if(zerodummy->next != nullptr){
            head=zerodummy->next;   
        }
        else if(onedummy->next != nullptr){
            head=onedummy->next;
        }
        else{
            head=twodummy->next;
        }
        
        return head;
        
    }
};

int main() {
    
    return 0;
}