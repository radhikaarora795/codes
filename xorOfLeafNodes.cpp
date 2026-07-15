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

void dfs(TreeNode* root, int& ans){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        ans=ans^(root->val);
    }
    dfs(root->left,ans);
    dfs(root->right,ans);
}

int xorSum(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int ans=0;
    dfs(root,ans);
    return ans;
}

int main() {
    
    return 0;
}