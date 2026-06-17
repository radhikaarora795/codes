/*

Problem Statement

A tree is considered special if the sums of all the nodes at each level are in an Arithmatic Progression (AP) Given root node of a binary tree. Return an array representing the minimum number that can be added at each level to make that tree special.

Input 1 :

 3
/  \
2  7
\
 15
Output: [0, 0, 0]

Input 2 :

  17
 /  \
11   5
       \
	   12
Output : [0,0,3]

Input 3 :

   1
  /  \
 11   5
/      \
2      10
\
 50
Output : [0,0,19,-4]

Time : O(n)
Space: O(n)

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr)
        {}
};

class Solution{
public:
    vector<int> makeSpecial(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> levelSum;

        while(!q.empty()){
            int s=q.size();
            int sum=0;
            for(int i=0;i<s;i++){
                auto ptr=q.front();
                q.pop();
                
                sum+=ptr->val;

                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }
            levelSum.push_back(sum);
        }

        int levels=levelSum.size();
        vector<int> ans(levels,0);

        if(levels<=2){
            return ans;
        }

        int d=levelSum[1]-levelSum[0];

        for(int i=0;i<levels;i++){
            int target=levelSum[0]+i*d;       // an=a+(n-1)d
            ans[i]=target-levelSum[i];
        }

        return ans;
    }
};

int main() {
    
    return 0;
}