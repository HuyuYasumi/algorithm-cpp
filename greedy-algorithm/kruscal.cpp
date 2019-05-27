#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * 点结构
 */
struct  Vertex {
    int id;
    vector<Vertex *> *v;  // 存储在图 P 中与当前顶点相连的点的向量，向量的长度极为该顶点的度

    explicit Vertex(int id) : id(id) {
        v = new vector<Vertex*>;
    }
};

/**
 * 边结构
 */
struct Edge {
    int w;  // 权重
    Vertex *u;
    Vertex *v;

    Edge(int w, Vertex *u, Vertex *v) : w(w), u(u), v(v) {}

    /**
     * 用于排序的接口
     */
    bool operator<=(Edge e) {
        return w <= e.w;
    }
};

/**
 * 用于排序的函数
 */
bool compare(Edge *e1, Edge *e2) {
    return *e1 <= *e2;
}

/**
 * 使用 BFS 搜索实现判断两顶点在图 P 中是否连通
 * @param n 图 P 中顶点的数量
 */
bool isConnected(int n, Vertex* a, Vertex* b) {
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    queue<Vertex*> queue1;
    queue1.push(a);
    while(!queue1.empty()) {
        Vertex* tmp = queue1.front();
        visited[tmp->id] = true;
        for(auto vertex : *tmp->v) {
            if(vertex->id == b->id)
                return true;
            if(!visited[vertex->id])
                queue1.push(vertex);
        }
        queue1.pop();
    }
    return false;
}

int kruscal(int **g, int n, vector<Edge *> *p) {
    // 首先，构建顶点集
    Vertex *v[n];
    for (int i = 0; i < n; ++i) {
        v[i] = new Vertex(i);
    }

    // 然后，构建边集
    vector<Edge*> E;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(g[i][j] > 0) {
                E.push_back(new Edge(g[i][j], v[i], v[j]));
            }
        }
    }

    sort(E.begin(), E.end(), compare);

    int res = 0;
    for (int i = 0, j = 0; j < E.size() && i <  n - 1; j++) {
        Edge* tmp = E[j];
        if(!isConnected(n, tmp->u, tmp->v)) {
            tmp->u->v->push_back(tmp->v);  // 往 u 的相连点集中添加 v
            tmp->v->v->push_back(tmp->u);  // 往 v 的相连点集中添加 u
            p->push_back(tmp);
            res += E[j]->w;
            i++;
        }
    }

    return res;
}

int main() {
    int vNum = 6;
    int *g[] = {
            new int[vNum]{0, 34, 46, 0, 0, 19},
            new int[vNum]{34, 0, 0, 0, 12, 0},
            new int[vNum]{46, 0, 0, 17, 0, 25},
            new int[vNum]{0, 0, 17, 0, 38, 25},
            new int[vNum]{0, 12, 0, 38, 0, 26},
            new int[vNum]{19, 0, 25, 25, 26, 0},
    };
    vector<Edge*>* P = new vector<Edge*>;
    cout << "Total Weight: " << kruscal(g, vNum, P) << endl;
    for (auto e : *P) {
        cout << "w: " << e->w << ", u.id: " << e->u->id << ", v.id: " << e->v->id << endl;
    }
    return 0;
}
