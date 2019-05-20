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
 * 判断顶点 v 在图 P 中是否即将产生分支
 */
bool hasBranch(Vertex* v) {
    return v->v->size() >= 2;
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

int tsp_II(int *g[], int n, vector<Edge*>* p) {
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

    int res = 0;  // 最短回路的长度
    // 为 p 找到前 n - 1 条边
    for(int i = 0; p->size() < n - 1; ++i) {
        Edge* tmp = E[i];
        if(!hasBranch(tmp->u) && !hasBranch(tmp->v) && !isConnected(n, tmp->u, tmp->v)) {
            res += tmp->w;
            tmp->u->v->push_back(tmp->v);  // 往 u 的相连点集中添加 v
            tmp->v->v->push_back(tmp->u);  // 往 v 的相连点集中添加 u
            p->push_back(tmp);
        }
    }

    // 连接起点与终点, 为 p 构成回路
    int v1 = -1, v2 = -1;
    for (auto e : *p) {
        if(e->u->v->size() == 1) {
            if (v1 == -1)
                v1 = e->u->id;
            else if (v2 == -1)
                v2 = e->u->id;
        }
        if(e->v->v->size() == 1) {
            if(v1 == -1)
                v1 = e->v->id;
            else if(v2 == -1)
                v2 = e->v->id;
        }
    }
    p->push_back(new Edge(g[v1][v2], v[v1], v[v2]));
    res += g[v1][v2];

    return res;
}

int main() {
    int n = 5;
    int g[5][5] = {
            {0, 3, 3, 2, 6},
            {3, 0, 7, 3, 2},
            {3, 7, 0, 2, 5},
            {2, 3, 2, 0, 3},
            {6, 2, 5, 3, 0},
    };
    int *g2[n];
    for (int i = 0; i < n; ++i) {
        g2[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            g2[i][j] = g[i][j];
        }
    }
    vector<Edge*>* P = new vector<Edge*>;
    cout << tsp_II(g2, n, P) << endl;
    for (auto e : *P) {
        cout << "w: " << e->w << ", u.id: " << e->u->id << ", v.id: " << e->v->id << endl;
    }
    return 0;
}
