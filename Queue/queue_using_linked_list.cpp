#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Queue {
    public:
    int size;
    ListNode *head;
    ListNode *tail; //注意链表的方向和队列方向的关系.链表头出队,链表尾入队. tip:对于单向链表, 头尾都可以入队. 但是出队不能在尾部, 因为tail指针会找不到上一个节点;

    Queue() : size(0), head(nullptr), tail(nullptr) {}

    void push(int val) {
        ListNode *new_node = new ListNode(val);
        if(size == 0) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = tail -> next;
        }
        size++;
    }

    int pop() {
        ListNode *temp = head;
        head = head->next;
        size--;
        int r = temp->val;
        delete temp;
        return r;
    }

    int get_head() {
        int r = head->val;
        return r;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << q.pop() << endl << q.pop() << endl;
    q.push(8);
    for(int i = 1; i <= 5; i++) {
        cout << q.pop() << endl;
    }

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    cout << q.pop() << endl << q.pop() << endl;
    q.push(8);
    for(int i = 1; i <= 5; i++) {
        cout << q.pop() << endl;
    }
    return 0;
}