#include <bits/stdc++.h>
using namespace std;

int left(int index) {
    return 2*index+1;
}

int right(int index) {
    return 2*index+2;
}

int parent(int index) {
    return (index-1)/2;
}

void sift_down(vector<int> &data, int index) { //最大堆的元素下沉, 理解两个if的条件
    int n = data.size();
    while(true) {
        int l = left(index);
        int r = right(index);
        int m_index = index;
        if (l < n && data[index] < data[l]) {
            m_index = l;
        }
        if (r < n && data[l] < data[r] && data[index] < data[r]) {
            m_index = r;
        }
        if (m_index == index) {
            break;
        }
        swap(data[m_index], data[index]); //swap交换函数
        index = m_index;
    }
}

void build_heap(vector<int> &data) {
    for (int i = parent(data.size() - 1); i >= 0; i--) { //叶子结点不需要下沉;从最后一个非叶子结点开始下沉,最后是根节点,实现全树的堆化
        sift_down(data, i);
    }
}

void sift_up(vector<int> &data, int index) {
    while (true) {
        int p = parent(index);
        if(p >= 0 && data[p] < data[index]) {
            swap(data[p], data[index]);
            sift_up(data, p);
            index = p;
        } else {
            break;
        }
    }
        
}

void push(vector<int> &data, int val) {
    data.push_back(val);
    sift_up(data, data.size() - 1);
}

int pop(vector<int> &data, int index) { 
    swap(data[index], data[data.size() - 1]);
    int r = data[data.size() - 1];
    data.pop_back();
    build_heap(data);
    return r;
}

int pop_top(vector<int> &data) {
    swap(data[0], data[data.size() - 1]);
    int r = data[data.size() - 1];
    data.pop_back();
    sift_down(data, 0);
    return r;
}

int main() {
    vector<int> data = {5,6,3,1,4,9,2,7};
    build_heap(data);

    push(data, 19);
    push(data, 8);
    push(data, 0);

    cout << pop(data, 3) << endl;
    
    cout << pop_top(data) << endl;

    return 0;
}