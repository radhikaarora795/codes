#include <iostream>
using namespace std;


/*

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

*/

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
    int solve(TreeNode* root, int curr){
        if(root == nullptr){
            return 0;
        }
        curr = curr*10 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            return curr;
        }

        return solve(root->left,curr)+solve(root->right,curr);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};

int main() {
    
    return 0;
}