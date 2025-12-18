#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    //入队
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    //访问队首元素
    cout << q.front() << endl;
    //出队
    q.pop();
    cout << q.front() << endl;
    //获取队列长度
    int length = q.size();
    return 0;
}