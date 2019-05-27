#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int id;
    int s;
    int f;

    Activity(int id, int s, int f) : id(id), s(s), f(f) {}
};

bool compare(Activity* a, Activity* b) {
    return a->f <= b->f;
}

void activity(int S[], int F[], int n, vector<Activity*>* B) {
    vector<Activity*> A;
    for (int i = 0; i < n; ++i) {
        A.push_back(new Activity(i, S[i], F[i]));
    }
    sort(A.begin(), A.end(), compare);

    B->push_back(A[0]);
    for (int i = 1; i < n; ++i) {
        if(A[i]->s >= B->back()->f)
            B->push_back(A[i]);
    }
}

int main() {
    int n = 11;
    int s[] = {8, 3, 5, 3, 1, 5, 6, 0, 2, 8, 12};
    int f[] = {11, 5, 7, 8, 4, 9, 10, 6, 13, 12, 14};
    auto *B = new vector<Activity*>();
    activity(s, f, n, B);
    for (auto a : *B) {
        cout << a->id << "\t";
    }
    return 0;
}
