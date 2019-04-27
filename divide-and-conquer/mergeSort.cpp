#include <iostream>
using namespace std;

void merge(int nums[], int lo, int min, int hi) {
    int size = hi - lo + 1;
    int numsCp[size];
    for(int i = 0; i < size; i++)
        numsCp[i] = nums[i + lo];

    int idx = hi;
    hi -= lo;
    lo = 0;
    int hiLeft = min = (hi + lo) >> 1;

    while(hiLeft >= lo && hi > min) {
        if(numsCp[hiLeft] > numsCp[hi]) {
            nums[idx--] = numsCp[hiLeft--];
        } else {
            nums[idx--] = numsCp[hi--];
        }
    }
    while(hiLeft >= lo)
        nums[idx--] = numsCp[hiLeft--];
    while(hi > min)
        nums[idx--] = numsCp[hi--];
}

void mergeSort(int nums[], int lo, int hi) {
    if(lo < hi) {
        int min = (lo + hi) / 2;
        mergeSort(nums, lo, min);
        mergeSort(nums, min + 1, hi);
        merge(nums, lo, min, hi);
    }
}

int main() {
    int nums[] = {4, 3, 8, 3, 5};
    int nums2[] = {6, 4, 3, 1, 1, -3};
    mergeSort(nums2, 0, 5);
    mergeSort(nums, 0, 4);
    return 0;
}
