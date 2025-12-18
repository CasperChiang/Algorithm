#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <cstdint>
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
    if(index > data.size() || data[index] == INT_MAX) {
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

void level_order_traverse(queue<TreeNode*> q) {
    TreeNode *node = nullptr;
    while(q.size() > 0) {
        node = q.front();
        cout << node->val << " ";
        q.pop();
        if(node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}

int main() {
    vector<int> array_tree = {1,2,3,4,5,6,INT_MAX,7,8,9,INT_MAX,INT_MAX,10,INT_MAX,INT_MAX};
    //INT_MAX INT_MIN分别表示int数据的最大上限和最小负数下限
    TreeNode *root = build_tree(array_tree, 0);
    pre_order_traverse(root);
    cout<<endl;
    in_order_traverse(root);
    cout<<endl;
    post_order_traverse(root);
    cout<<endl;
    queue<TreeNode*> q;
    q.push(root);
    level_order_traverse(q);
    return 0;
}


