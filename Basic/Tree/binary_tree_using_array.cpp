#include <bits/stdc++.h>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <vector>
using namespace std;

class BinaryTree {
    public:
    int size;
    vector<int> data;

    BinaryTree(vector<int> v) : size(v.size()), data(v) {}

    int left(int i) {
        return 2*i+1;
    }
    int right(int i) {
        return 2*i+2;
    }
    int parent(int i) {
        return (i-1)/2;
    }

    void pre_order_traverse(int i) {
        cout << data[i] << " ";
        if(left(i) < size && data[left(i)] != INT_MAX) {
            pre_order_traverse(left(i));
        }
        if(right(i) < size && data[right(i)] != INT_MAX) {
            pre_order_traverse(right(i));
        }
    }
    void in_order_traverse(int i) {
        if(left(i) < size && data[left(i)] != INT_MAX) {
            in_order_traverse(left(i));
        }
        cout << data[i] << " ";
        if(right(i) < size && data[right(i)] != INT_MAX) {
            in_order_traverse(right(i));
        }
    }
    void post_order_traverse(int i) {
        if(left(i) < size && data[left(i)] != INT_MAX) {
            post_order_traverse(left(i));
        }
        if(right(i) < size && data[right(i)] != INT_MAX) {
            post_order_traverse(right(i));
        }
        cout << data[i] << " ";
    }
};

int main() {
    //按照层序遍历的顺序用数组表示二叉树
    vector<int> tree = {1,2,3,4,5,6,INT_MAX, 7,8,INT_MAX,INT_MAX,INT_MAX,9};
    BinaryTree t(tree);
    t.pre_order_traverse(0);
    cout << endl;
    t.in_order_traverse(0);
    cout << endl;
    t.post_order_traverse(0);
    cout << endl;
    return 0;
}