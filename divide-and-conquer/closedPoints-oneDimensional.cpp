#include <iostream>
using namespace std;

int Partition(int nums[], int lo, int hi) {
    while(lo < hi) {
        while(lo < hi && nums[lo] <= nums[hi])
            hi--;
        if(nums[lo] > nums[hi]) {
            int tmp = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = tmp;
            lo++;
        }
        while(lo < hi && nums[lo] <= nums[hi])
            lo++;
        if(nums[lo] > nums[hi]) {
            int tmp = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = tmp;
            hi--;
        }
    }
    return lo;
}

void QuickSort(int nums[], int lo, int hi) {
    if(lo < hi) {
        int n = Partition(nums, lo, hi);
        QuickSort(nums, lo, n - 1);
        QuickSort(nums, n + 1, hi);
    }
}

int closestPoint(int *P, int lo, int hi) {
    if(hi - lo == 1)
        return P[hi] - P[lo];
    int min = (lo + hi) >> 1;
    int disL = closestPoint(P, lo, min);
    int disR = closestPoint(P, min, hi);
    int dis = P[min + 1] - P[min - 1];
    if(dis <= disL && dis <= disR)
        return dis;
    else if(disL <= disR)
        return disL;
    else
        return disR;
}

int main() {
    int size;
    int* P;
    cout << "The size of Point Set: ";
    cin >> size;
    P = new int[size];
    for(int i = 0; i < size; i++) {
        cout << i << ": ";
        cin >> P[i];
    }
    QuickSort(P, 0, size - 1);
    cout << "The dis is " << closestPoint(P, 0, size - 1);
    return 0;
}
