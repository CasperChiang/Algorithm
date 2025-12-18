#include <bits/stdc++.h>
using namespace std;

class Stack {
    private: vector<int> data;
    public: 
    Stack() {

    } //可省略. 自带无参构造函数
    int get_size() {
        return data.size();
    }
    void push(int val) {
        data.push_back(val);
    }
    int get_top() {
        return data[data.size() - 1];
    }
    int pop() {
        int r = get_top();
        data.erase(data.end() - 1); //data.end()是最后一个索引+1的虚拟索引位置.
        return r;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}