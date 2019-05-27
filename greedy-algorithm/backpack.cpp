#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Good {
    int id;
    int v;
    int w;
    double u;

    Good() = default;

    Good(int id, int v, int w) : id(id), v(v), w(w) {
        u = (double)v / w;
    }
};

bool compare(Good *a, Good *b) {
    return a->u >= b->u;
}

int backpack(int V[], int W[], int n, int w, int X[]) {
    vector<Good*> Goods;
    for (int i = 0; i < n; ++i) {
        Goods.push_back(new Good(i, V[i], W[i]));
        X[i] = 0;
    }
    sort(Goods.begin(), Goods.end(), compare);

    int totalW = 0;
    for (int i = 0; i < Goods.size() && Goods[i]->w <= w; ++i) {
        X[Goods[i]->id] = 1;
        w -= Goods[i]->w;
        totalW += Goods[i]->v;
    }
    return totalW;
}

int main() {
    int n = 5;
    int w = 10;
    int W[] = {4, 2, 6, 5, 4};
    int V[] = {6, 3, 5, 4, 6};
    int X[n];
    cout << backpack(V, W, n, 10, X) << endl;
    for (int i = 0; i < n; ++i) {
        cout << X[i] << "\t";
    }
    return 0;
}
