/*
Binary tree where each node stores its data and the absolute difference of 
its left and right child values
*/

#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     int difference;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), difference(0),left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), difference(0),left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), difference(0), left(left), right(right) {}
};

/* A binary tree where each node has two values one the original data and 
second the absolute difference between the left and right child. Every node 
should satisfy the children’s property i.e. the absolute difference between 
the left and right child should be equal to node’s second value. If the tree 
satisfies this property then return 1 
*/

bool check(TreeNode *root){
    if(root == nullptr){
        return true;
    }
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }
    if(root->left == nullptr || root->right == nullptr){
        return false;
    }
    int diff=abs(root->left->val - root->right->val);
    return (root->difference == diff) && check(root->left) && check(root->right);
}

int main() {
    
    return 0;
}