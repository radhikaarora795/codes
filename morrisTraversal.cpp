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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr=root;

        while(curr != nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                // inordered predeccsor: rightmost node of left subtree
                // from ip create a temperaory link from right to root
                TreeNode *ip=curr->left;
                while(ip->right != nullptr && ip->right != curr){
                    ip=ip->right;
                }
                if(ip->right == nullptr){
                    ip->right=curr;     // create link
                    curr=curr->left;
                }
                else{
                    ip->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }

            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}