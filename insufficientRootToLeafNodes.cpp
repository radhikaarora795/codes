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

class Solution {
public:
    TreeNode* DFS(TreeNode* root, int sum,int limit){
        if(root == nullptr){
            return nullptr;
        }
        sum+=root->val;

        if(root->left == nullptr && root->right == nullptr){
            return sum >= limit ? root:nullptr;
        }

        root->left=DFS(root->left,sum,limit);
        root->right=DFS(root->right,sum,limit);

        if(root->left == nullptr && root->right == nullptr){
            return nullptr;
        }

        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return DFS(root,0,limit);
    }
};

int main() {
    
    return 0;
}