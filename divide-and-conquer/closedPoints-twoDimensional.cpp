#include<iostream>
#include <cmath>
using namespace std;

class Point {
public:
    int x{};
    int y{};

    Point() = default;

    Point(int x, int y) : x(x), y(y) {}

    double distanceOf(Point p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int Partition(Point P[], int lo, int hi) {
    while(lo < hi) {
        while(lo < hi && P[lo].y <= P[hi].y)
            hi--;
        if(P[lo].y > P[hi].y) {
            Point tmp = P[lo];
            P[lo] = P[hi];
            P[hi] = tmp;
            lo++;
        }
        while(lo < hi && P[lo].y <= P[hi].y)
            lo++;
        if(P[lo].y > P[hi].y) {
            Point tmp = P[lo];
            P[lo] = P[hi];
            P[hi] = tmp;
            hi--;
        }
    }
    return lo;
}

void QuickSort(Point P[], int lo, int hi) {
    if(lo < hi) {
        int n = Partition(P, lo, hi);
        QuickSort(P, lo, n - 1);
        QuickSort(P, n + 1, hi);
    }
}

double closestPoint(Point P[], int lo, int hi) {
    if(hi - lo == 1)
        return P[hi].distanceOf(P[lo]);
    int mid = (lo + hi) >> 1;
    double disL = closestPoint(P, lo, mid);
    double disR = closestPoint(P, mid, hi);
    double d = (disL <= disR ? disL : disR);
    Point T[hi - lo + 1];
    int idx = 0;
    for(int i = mid - 1; i >= lo && P[mid].x - P[i].x < d; i--)
        T[idx++] = P[i];
    for(int i = mid + 1; i <= hi && P[i].x - P[mid].x < d; i++)
        T[idx++] = P[i];
    QuickSort(T, 0, idx - 1);
    for(int i = 0; i < idx; i++)
        for(int j = i + 1; j < idx; j++) {
            if(T[j].y - T[i].y < d) {
                double dis = T[j].distanceOf(T[i]);
                d = (d <= dis ? d : dis);
            }
        }
    return d;
}

int main() {
    const int SIZE = 5;
    Point P[SIZE] = {
            Point(1, 43),
            Point(14, 11),
            Point(26, 36),
            Point(34, 83),
            Point(54, 83)
    };
    cout << closestPoint(P, 0, SIZE - 1);
    return 0;
}
