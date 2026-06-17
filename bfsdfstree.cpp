#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    node(int d): data(d), left(nullptr), right(nullptr)
        {}
};

node *insertNode(node *root, int data){
    if(root == nullptr){
        return new node(data);
    }

    if(data<=root->data){
        root->left=insertNode(root->left,data);
    }
    else{
        root->right=insertNode(root->right,data);
    }

    return root;
}

vector<vector<int>> bfs(node *root){
    if(root == nullptr)
        return {};

    vector<vector<int>> result;
    queue<node *> q;
    if(root != nullptr){
        q.push(root);
    }
    while(!q.empty()){
        vector<int> level;
        int s=q.size();
        for(int i=0;i<s;i++){
            node *ptr=q.front();
            q.pop();
            level.push_back(ptr->data);
            if(ptr->left != nullptr){
                q.push(ptr->left);
            }
            if(ptr->right != nullptr){
                q.push(ptr->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

int height(node *root){
    if(root == nullptr){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}

int main() {
    node *root=nullptr;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    bfs(root);

    return 0;
}