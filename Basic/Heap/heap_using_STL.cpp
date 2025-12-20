#include<bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> min_heap; //greater建立的是最小堆
    priority_queue<int, vector<int>, less<int>> max_heap; //less建立的是最大堆, 只有最大堆可以简写priority_queue<int> max_heap;

    //入堆
    max_heap.push(1);
    max_heap.push(3);
    max_heap.push(2);
    max_heap.push(5);
    max_heap.push(4);

    //访问堆顶
    int top = max_heap.top();
    cout << top << endl;

    //堆顶出堆
    max_heap.pop();
    cout << max_heap.top() << endl;

    //获取大小
    int size = max_heap.size();

    //根据已有vector建堆
    vector<int> data = {4,7,2,3};
    priority_queue<int, vector<int>, less<int>> heap(data.begin(), data.end());

    return 0;
}