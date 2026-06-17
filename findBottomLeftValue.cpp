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

/*
Given the root of a binary tree, return the leftmost value in the 
last row of the tree.
*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        /*
        BFS (Level Order) Solution Idea
        For every level, store the first node.
        The first node of the last level is the answer.
        */
        if(root == nullptr){
            return -1;
        }
        queue<TreeNode *> q;
        q.push(root);
        int ans=root->val;
        // vector<vector<int>> result;
        while(!q.empty()){
            int s=q.size();
            ans=q.front()->val;
            // vector<int> level;
            for(int i=0;i<s;i++){
                TreeNode *ptr=q.front();
                q.pop();
                // level.push_back(ptr->val);
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }

                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }
            // result.push_back(level);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}