#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build_tree(vector<int> data, int index) {
    if(index > data.size() || data[index] == 0) {
        return nullptr;
    }
    TreeNode *node = new TreeNode(data[index]);
    node->left = build_tree(data, 2*index+1);
    node->right = build_tree(data, 2*index+2);
    return node;
}

void pre_order_traverse(TreeNode* root) {
    cout << root->val << " ";
    if(root->left != nullptr) {
        pre_order_traverse(root->left);
    }
    if(root->right != nullptr) {
        pre_order_traverse(root->right);
    }
}

void in_order_traverse(TreeNode* root) {
    if(root->left != nullptr) {
        in_order_traverse(root->left);
    }
    cout << root->val << " ";
    if(root->right != nullptr) {
        in_order_traverse(root->right);
    }
}

void post_order_traverse(TreeNode* root) {
    if(root->left != nullptr) {
        post_order_traverse(root->left);
    }
    if(root->right != nullptr) {
        post_order_traverse(root->right);
    }
    cout << root->val << " ";
}

int main() {
    vector<int> array_tree = {1,2,3,4,5,6,0,7,8,9,0,0,10,0,0};
    TreeNode *root = build_tree(array_tree, 0);
    pre_order_traverse(root);
    cout<<endl;
    in_order_traverse(root);
    cout<<endl;
    post_order_traverse(root);
    cout<<endl;
    return 0;
}