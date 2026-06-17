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
Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 
*/

class Solution {
public:
    void preorderDFS(TreeNode *root,vector<int>& result){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            result.push_back(root->val);
        }

        preorderDFS(root->left,result);
        preorderDFS(root->right,result);
    }

    // compare left to right and right to left
    void preorderDFSRight(TreeNode *root,vector<int>& result){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            result.push_back(root->val);
        }

        preorderDFSRight(root->right,result);
        preorderDFSRight(root->left,result);
    }

    // number of mismatched leaves
    int leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        vector<int> result2;

        preorderDFS(root1,result1);
        preorderDFSRight(root2,result2);

        int r1=result1.size();
        int r2=result2.size();

        int count=0;

        for(int i=0;i<min(r1,r2);i++){
            if(result1[i] != result2[i]){
                count++;
            }
        }

        return count+abs(r1-r2);
    }
};

int main() {
    
    return 0;
}