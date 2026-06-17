#include <iostream>
using namespace std;

/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Idea

While traversing the tree, keep track of the maximum value encountered so 
far on the current root-to-node path.

For every node:

If node->val >= maxValue, it is a good node.
Update maxValue.
Continue DFS on left and right children.
*/

class Solution {
public:
    int count=0;
    void dfs(TreeNode* root,int maxValue){
        if(root == nullptr){
            return;
        }
        if(root->val >= maxValue){
            count++;
        }

        maxValue=max(maxValue,root->val);
        
        dfs(root->left,maxValue);
        dfs(root->right,maxValue);
    }

    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return count;
    }
};

int main() {
    
    return 0;
}