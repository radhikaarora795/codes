#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    Node *lca(Node* root, int p, int q){
        if(root == nullptr){
            return nullptr;
        }
        if(root->data == p|| root->data == q){
            return root;
        }
        Node* left=lca(root->left,p,q);
        Node* right=lca(root->right,p,q);
        
        if(left != nullptr && right != nullptr){
            return root;
        }
        
        if(left != nullptr){
            return left;
        }
        
        if(right != nullptr){
            return right;
        }
        
        return nullptr;
    }
    
    int dist(Node* root, int target){
        if(root == nullptr){
            return -1;
        }
        if(root->data == target){
            return 0;
        }
        
        int left=dist(root->left,target);
        if(left != -1) return left+1;
        
        int right=dist(root->right,target);
        if(right != -1) return right+1;
        
        return -1;
    }
  
    int findDist(Node* root, int a, int b) {
        // code here
        Node* LCA=lca(root,a,b);
        return dist(LCA,a)+dist(LCA,b);
        
        
    }
};

int main() {
    
    return 0;
}