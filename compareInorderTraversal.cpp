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

void inorder(TreeNode *root,vector<int>& ans){
    if(root == nullptr){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

bool compare(TreeNode *root1, TreeNode *root2){
    vector<int> ans1;
    vector<int> ans2;
    inorder(root1,ans1);
    inorder(root2,ans2);
    return ans1==ans2;
}

int main() {
    
    return 0;
}