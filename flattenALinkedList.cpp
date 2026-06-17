#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; 

class Solution {
  public:
    struct compare{
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }  
    };
  
    Node *flatten(Node *root) {
        // code here
        priority_queue<Node*,vector<Node*>,compare> pq;
        Node *curr=root;
        while(curr != nullptr){     // saare vertical list ke head push kr diye
            pq.push(curr);
            curr=curr->next;
        }
        Node *dummy = new Node(-1);
        Node *last=dummy;
        
        while( !pq.empty()){
            Node* ptr = pq.top();
            pq.pop();
            if(ptr->bottom!= nullptr){
                pq.push(ptr->bottom);
            }
            ptr->next = nullptr;
            last->bottom=ptr;
            last = ptr;
            // last->next = nullptr;
            
        }
        
        return dummy->bottom;
    }
};

int main() {
    
    return 0;
}