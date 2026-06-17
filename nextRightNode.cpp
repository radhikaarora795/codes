#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node *nextRight(Node *root, int key) {
        // code here
        queue<Node *> q;
        if(root != nullptr){
            q.push(root);
        }
        
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                Node *ptr=q.front();
                q.pop();
                if(ptr->data == key){
                    if(i == s-1){       // this means this is the last node
                        return new Node(-1);
                    }
                    return q.front();
                }
                if(ptr -> left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr -> right != nullptr){
                    q.push(ptr->right);
                }
            }
        }
        
        return new Node(-1);
    }
};

int main() {
    
    return 0;
}