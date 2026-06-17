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
    int findBottomRightValue(TreeNode* root) {
        // The last node processed in the entire BFS will be the bottom-right node.
        if(root == nullptr){
            return -1;
        }
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *ptr=nullptr;
        while(!q.empty()){
            ptr=q.front();
            q.pop();
            if(ptr->left != nullptr){
                q.push(ptr->left);
            }
            if(ptr->right != nullptr){
                q.push(ptr->right);
            }
        }
        return ptr->val;
    }
};

int main() {
    
    return 0;
}