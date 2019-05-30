#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task {
    int idx;
    int time;

    task() = default;

    task(int idx, int time) : idx(idx), time(time) {}
};

bool compare(task* a, task* b) {
    return a->time >= b->time;
}

int min(int d[], int m) {
    int min = d[0];
    int idx = 0;
    for (int i = 1; i < m; ++i) {
        if(min > d[i]) {
            min = d[i];
            idx = i;
        }
    }
    return idx;
}

/*
 * @param S 每台机器处理的作业
 */
int scheduling(int t[], int n, int m, vector<int> S[]) {
    vector<task*> tasks;   // 存储所有的作业
    for (int i = 0; i < n; ++i) {
        tasks.push_back(new task(i, t[i]));
    }
    sort(tasks.begin(), tasks.end(), compare);

    int D[m];  // 每台机器的空闲时间
    int i = 0;
    for (int i = 0; i < m; ++i) {
        D[i] = 0;
    }

    for (; i < m && i < n; ++i) {
        S[i].push_back(tasks[i]->idx);
        D[i] = tasks[i]->time;
    }
    for (; i < n; ++i) {
        int idx = min(D, m);
        S[idx].push_back(tasks[i]->idx);
        D[idx] += tasks[i]->time;
    }

    int max = 0;
    for (i = 0; i < m; ++i) {
        if(max < D[i])
            max = D[i];
    }
    return max;
}

int main() {
    int n = 7;
    int m = 3;
    int t[] = {2, 14, 4, 16, 6, 5, 3};
    vector<int> S[m];
    cout << scheduling(t, n, m, S) << endl;

    for (int i = 0; i < m; ++i) {
        cout << "machine No." << i << ": ";
        for (auto idx : S[i]) {
            cout << "task No." << idx << "    ";
        }
        cout << endl;
    }
    return 0;
}
