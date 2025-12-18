#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {} //构造函数
};

ListNode* init_list(const vector<int> data) {
    ListNode* p = new ListNode(-1);
    ListNode* r = p;
    for(int val : data) {
        ListNode* new_node = new ListNode(val);
        p->next = new_node;
        p = new_node;
    }
    return r;
}

void print_list(ListNode *r) {
    ListNode *p = r;
    while(p->next != nullptr) {
        p = p->next;
        cout << p->val << " ";
    }
    cout << "\n";
}

void insert_node(int val, ListNode *tar) { //理解为什么不是*&tar: 因为没有修改指针本身,而是修改指针指向的空间.
    ListNode *new_node = new ListNode(val);
    ListNode *temp = tar->next;
    tar->next = new_node;
    new_node->next = temp;
}

void remove_node(ListNode *tar) {
    ListNode *temp = tar->next;
    tar->next = tar->next->next;
    delete temp; //必须手动释放内存
}

int main() {
    vector<int> data = {1,2,3,4,5,6,7,8,9};
    ListNode* list = init_list(data);
    print_list(list);
    insert_node(300, list->next->next->next);
    print_list(list);
    remove_node(list->next->next->next);
    print_list(list);
    return 0;
}