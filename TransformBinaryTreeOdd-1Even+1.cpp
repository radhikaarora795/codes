/*
Transform a binary tree so that every odd left child is subtracted by 1 and 
every even left child is added by 1 — in linear time and constant space.
*/

#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void transform(TreeNode *root){
    if(root == nullptr){
        return;
    }
    TreeNode *curr=root;

    while(curr != nullptr){
        if(curr->left == nullptr){
            // ans.pushback(curr->val)
            curr=curr->right;
        }
        else{
            TreeNode *ip=curr->left;
            while(ip->right != nullptr && ip->right != curr){
                ip=ip->right;
            }
            if(ip->right == nullptr){
                // Apply the transformation to the left child before moving down.
                if(curr->left->val % 2 == 0 ){
                    curr->left->val+=1;
                }
                else{
                    curr->left->val-=1;
                }
                ip->right=curr;
                curr=curr->left;
            }
            else{
                ip->right=nullptr;
                // ans.pushback(curr->val)
                curr=curr->right;
            }
        }
    }
}

int main() {
    
    return 0;
}