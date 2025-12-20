#include<bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    //普通数组
    int arr[5];
    int nums[5] = {1, 3, 2, 5, 4};
    //定义和初始化
    vector<int> array_1;
    array_1 = {-1, -2, -3};
    vector<float> array_2 = {1, 2, 3, 4, 5};
    //访问
    cout << array_2[1] << "\n";
    //添加和插入
    array_2.push_back(6);
    array_2.insert(array_2.begin() + 1, 1.5);
    cout << array_2[1] << "\n";
    //删除
    array_2.erase(array_2.begin() + 1);
    cout << array_2[1] << "\n";
    //删除最后一个元素
    array_2.pop_back(); //或者array_2.erase(data.end() - 1);
    //获取长度
    int length = array_2.size();
    //遍历
    for (float val : array_2) {
        cout << val << " ";
    }
    cout << "\n";
    for (int i = 0; i < array_2.size(); i++) {
        cout << array_2[i] << " ";
    }
    cout << "\n";
    //拼接
    array_1.insert(array_1.end(), array_2.begin() + 1, array_2.end());
    //截取
    vector<int> sub1(array_2.begin() + 1, array_2.end() - 1); //左闭右开的两个参数. 特别注意, array_2.begin()指向索引0, 而array_2.end()指向最后一个索引+1的虚拟索引.
    //升序排序
    sort(array_1.begin(), array_1.end());
    //翻转和降序排序
    sort(array_1.begin(), array_1.end());
    reverse(array_1.begin(), array_1.end());
    //清空
    array_1.clear();
    return 0;
}