#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Graph {
    public:
    vector<int> v_list;
    vector<vector<int>> matrix;
    
    Graph(vector<int> vertices, vector<vector<int>> &edges) {
        for(int &v : vertices) {
            add_vertex(v);
        }
        for(vector<int> &e : edges) {
            add_edge(e);
        }
    }

    void add_edge(vector<int> e) {
        matrix[e[0]][e[1]] = 1;
        matrix[e[1]][e[0]] = 1;
    }

    void del_edge(vector<int> e) {
        matrix[e[0]][e[1]] = 0;
        matrix[e[1]][e[0]] = 0;
    }

    void add_vertex(int v) {
        v_list.push_back(v);
        for(vector<int> &i : matrix) {
            i.push_back(0);
        }
        matrix.push_back(vector<int>(v_list.size(),0));  //注意是怎么添加全0行的, 另外注意先添加列再添加行, 不然会多出一列.
    }

    void del_vertex(int index) {
        v_list.erase(v_list.begin() + index);
        matrix.erase(matrix.begin() + index);
        for(vector<int> &i : matrix) {
            i.erase(i.begin() + index);
        } 
    }

    void print_graph() {
        cout << "顶点列表: ";
        for(int v : v_list) {
            cout << v << " ";
        }
        cout << endl;
        
        cout << "邻接矩阵:" << endl;
        cout << "  ";
        for(int v : v_list) {
            cout << v << " ";
        }
        cout << endl;
        
        for(int i = 0; i < matrix.size(); i++) {
            cout << v_list[i] << " ";
            for(int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;
    }

    bool has_edge(int u, int v) {
        // 找到顶点u和v的索引
        auto it_u = find(v_list.begin(), v_list.end(), u);
        auto it_v = find(v_list.begin(), v_list.end(), v);
        
        if(it_u == v_list.end() || it_v == v_list.end()) return false;
        
        int idx_u = distance(v_list.begin(), it_u);
        int idx_v = distance(v_list.begin(), it_v);
        
        return matrix[idx_u][idx_v] == 1;
    }
    
};

void print(const vector<vector<int>> &vec, const string &title = "二维向量") {
    if (vec.empty()) {
        cout << title << ": 空" << endl;
        return;
    }

    cout << "┌─ " << title << " ";
    for (size_t i = 0; i < vec[0].size() * 4; ++i) {
        cout << "─";
    }
    cout << "┐" << endl;

    // 打印列号
    cout << "│   ";
    for (size_t j = 0; j < vec[0].size(); ++j) {
        cout << setw(3) << j << " ";
    }
    cout << "│" << endl;

    // 打印分隔线
    cout << "├───";
    for (size_t j = 0; j < vec[0].size(); ++j) {
        cout << "────";
    }
    cout << "┤" << endl;

    // 打印数据
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "│" << setw(2) << i << " │";
        for (const auto &elem : vec[i]) {
            cout << setw(3) << elem << " ";
        }
        cout << "│" << endl;
    }

    cout << "└───";
    for (size_t j = 0; j < vec[0].size(); ++j) {
        cout << "────";
    }
    cout << "┘" << endl;

    // 统计信息
    cout << "  尺寸: " << vec.size() << " × " << vec[0].size()
         << "，元素总数: " << vec.size() * vec[0].size() << endl;
}

int main() {
    vector<int> vertices = {0, 1, 2, 3};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    
    Graph g(vertices, edges);

    g.add_vertex(4);
    g.del_vertex(2);
    vector<int> new_edge = {1, 3};
    g.add_edge(new_edge);

    print(g.matrix);
    return 0;
}