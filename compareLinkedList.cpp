#include <iostream>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

// Compare two strings represented as linked lists similar to str_compare function in C
class Solution {
  public:
    int compare(Node *head1, Node *head2) {
        // Code Here
        if(head1 == nullptr && head2 == nullptr){
            return 0;
        }
        else if(head1 == nullptr && head2 != nullptr){
            return -1;
        }
        else if(head1 != nullptr && head2 == nullptr){
            return 1;
        }
        
        Node *l1=head1;
        Node *l2=head2;
        
        while(l1 != nullptr && l2 != nullptr){
            if(l1->data == l2->data){
                l1=l1->next;
                l2=l2->next;
            }
            else{
                if(l1->data > l2->data){
                    return 1;
                }
                else{
                    return -1;
                }
            }
        }
        
        if(l1 == nullptr && l2 != nullptr){
            return -1;
        }
        if(l2 == nullptr && l1 != nullptr){
            return 1;
        }
        
        return 0;
    }
};

int main() {
    
    return 0;
}