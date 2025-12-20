#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build_tree(vector<int> data, int index) { //借用之前构建树的方法
    if(index > data.size() || data[index] == INT_MAX) {
        return nullptr;
    }
    TreeNode *node = new TreeNode(data[index]);
    node->left = build_tree(data, 2*index+1);
    node->right = build_tree(data, 2*index+2);
    return node;
}

TreeNode* search_val(TreeNode *root, int tar) { //给出一种递归方法
    if(root->val == tar) {
        return root;
    }
    if (root->val > tar && root->left != nullptr) {
        return search_val(root->left, tar);
    }
    if (root->val < tar && root->right != nullptr) {
        return search_val(root->right, tar);
    }
    else {
        return nullptr;
    }
}

TreeNode* search_val_using_iter(TreeNode *root, int tar) { //一种迭代方法
    while (root->val != tar) {
        if (root->val > tar && root->left != nullptr) {
            root = root->left;
        }
        if (root->val < tar && root->right != nullptr) {
            root = root->right;
        }
        else {
            return nullptr;
        }
    }
    return root;
}

int main() {
    vector<int> tree = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
    TreeNode *root = build_tree(tree, 0);
    cout << search_val(root, 14)->val << endl;
    cout << search_val(root, 20) << endl;
    cout << search_val_using_iter(root, 14)->val << endl;
    cout << search_val_using_iter(root, 20) << endl;
    return 0;
}