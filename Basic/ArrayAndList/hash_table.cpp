#include <bits/stdc++.h>
using namespace std;
int main() {
    //定义
    unordered_map<int, string> map;
    //添加键值对
    map[2025100349] = "Harry";
    map[2022100223] = "Jack";
    map[2023304553] = "Raze";
    //查询
    cout << map[2025100349] << endl;
    //删除
    map.erase(2025100349);
    return 0;
}