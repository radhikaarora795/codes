#include <iostream>
using namespace std;


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node *dfs(Node* head){
        Node *curr=head;
        Node *last=head;

        while(curr != nullptr){
            Node* nextNode = curr->next;

            if(curr->child != nullptr){
                Node* childHead=curr->child;
                Node* childTail=dfs(childHead);

                curr->next=childHead;
                childHead->prev=curr;

                curr->child=nullptr;

                if(nextNode != nullptr){
                    childTail->next=nextNode;
                    nextNode->prev=childTail;
                }

                last=childTail;
            }
            else{
                last=curr;
            }
            curr=nextNode;
        }
        return last;
    }

    Node* flatten(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        dfs(head);
        return head;
    }
};

int main() {
    
    return 0;
}