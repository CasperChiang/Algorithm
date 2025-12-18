#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class MatrixGraph {
    vector<int> vertices;
    vector<vector<int>> matrix;
    
    public: MatrixGraph(const vector<int> &vertices, const vector<vector<int>> &edges) {
        for(int v : vertices) {
            add_vertex(v);
        }
        for(const vector<int> &e : edges) { //1.每个元素是容器,拷贝时候需要给每个先创建内存,再拷贝,复杂度高.通过&,能够直接引用.const是防止误改. 同时, const和&要放在接收处, 而不是原数据edges
            add_edge(e[0], e[1]);
        }
    }
    
    int get_size() {
        return vertices.size();
    }
    
    void add_vertex(int val) {
        int n = get_size();
        vertices.push_back(val);
        matrix.push_back(vector<int>(n, 0));
        for(vector<int> &row : matrix) {
            row.push_back(0);
        }
    }
    
    void remove_vertex(int index) {
        vertices.erase(vertices.begin() + index); //vertices.begin表明迭代器的第0个位置,必须写,只写index不是一种迭代器.
        matrix.erase(matrix.begin() + index);
        for(vector<int> &row : matrix) {
            row.erase(row.begin() + index);
        }
    }
    
    void add_edge(int a, int b) {
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    void delete_edge(int a, int b) {
        matrix[a][b] = 0;
        matrix[b][a] = 0;
    }
    
    void print_matrix() {
        for(int v : vertices) {
            cout << v << " ";
        }
        cout << "\n";
        for(const vector<int> &row : matrix) {
            for(int e : row) {
                cout << e << "";
            }
            cout << "\n";
        }
    }
};

int main() {
    vector<int> vertices = {0, 1, 2, 3};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    
    MatrixGraph g(vertices, edges);
    
    cout << "初始图邻接矩阵:" << endl;
    g.print_matrix();
    cout << endl;
    
    // 添加顶点
    g.add_vertex(4);
    cout << "添加顶点4后:" << endl;
    g.print_matrix();
    cout << endl;
    
    // 添加边
    g.add_edge(1, 4);
    cout << "添加边(1,4)后:" << endl;
    g.print_matrix();
    cout << endl;
    
    // 删除边
    g.delete_edge(0, 1);
    cout << "删除边(0,1)后:" << endl;
    g.print_matrix();
    cout << endl;
    
    // 删除顶点（索引2对应顶点2）
    g.remove_vertex(2);
    cout << "删除顶点2后:" << endl;
    g.print_matrix();
    
    return 0;
}