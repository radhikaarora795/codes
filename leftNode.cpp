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

/*
ind the Left Neighbor of a Given Node in a Binary Tree

Given a binary tree and a key, find the node immediately to the left of the node containing the key on the same level.

If the key node is the first node on its level (i.e., it has no left neighbor), return NULL
*/

class Solution {
  public:
    Node *nextLeft(Node *root, int key) {
        // code here
        queue<Node *> q;
        if(root != nullptr){
            q.push(root);
        }
    
        while(!q.empty()){
            int s=q.size();
            Node *prev=nullptr;

            for(int i=0;i<s;i++){
                Node *ptr=q.front();
                q.pop();
                if(ptr->data == key){
                    return prev;
                }
                prev=ptr;
                if(ptr -> left != nullptr){
                    q.push(ptr->left);
                    
                }
                if(ptr -> right != nullptr){
                    q.push(ptr->right);
                }
            }
        }
        
        return nullptr;
    }
};

int main() {
    
    return 0;
}