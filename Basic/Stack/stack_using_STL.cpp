#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    //入栈
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(4);
    //访问栈顶元素
    int top = s.top();
    //出栈
    s.pop(); //无返回值
    //获取长度
    int length = s.size();
    return 0;
}