#include <bits/stdc++.h>
using namespace std;

class Queue {
    public:
    int* data; //记住数组是怎么在类中定义和初始化的
    int size;
    int head;
    int tail;
    int max_size;

    Queue(int max_length) {
        data = new int[max_length]; //记住数组是怎么在类中定义和初始化的
        size = 0;
        head = 0;
        tail = max_length - 1;
        max_size = max_length;
    }

    void push(int val) {
        tail = (tail + 1) % max_size;
        data[tail] = val;
        size++;
    }

    int pop() {
        int r = data[head];
        head = (head + 1) % max_size;
        size--;
        return r;
    }

    int get_head() {
        return data[head];
    }
};

int main() {
    Queue q(10);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.get_head() << endl << q.pop() << endl << q.pop() << endl;
    q.push(8);
    cout << endl << q.get_head();
    return 0;
}