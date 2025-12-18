#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    public: //所有的类和结构体, 都添加public, 不会出错.
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Stack {
    public:
    ListNode *top;
    int stack_size;
    Stack() : top(nullptr), stack_size(0) {}
    int size() {
        return stack_size;
    }
    void push(int val) {
        ListNode *new_node = new ListNode(val);
        new_node->next = top; //空指针不能访问next指向别人, 但是别人可以指向空指针.
        top = new_node;
        stack_size++;
    }
    int get_top() {
        return top->val;
    }
    int pop() {
        int r = top->val;
        ListNode *temp = top;
        top = top->next;
        delete temp;
        stack_size--;
        return r;
    }
    vector<int> get_array() {
        ListNode *p = top;
        vector<int> r;
        while (p != nullptr) {
            r.push_back(p->val);
            p = p->next;
        }
        return r;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    for(int val : s.get_array()) {
        cout << val << " ";
    }
    cout << endl << s.pop() << endl;
    for(int val : s.get_array()) {
        cout << val << " ";
    }
    return 0;
}