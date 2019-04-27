#include <iostream>
using namespace std;

void swap(int nums[], int a, int b) {
    nums[a] += nums[b];
    nums[b] = nums[a] - nums[b];
    nums[a] -= nums[b];
}

void siftHeap(int nums[], int k, int n) {
    int idx = (k << 1) + 1;
    while(idx <= n) {
        if(idx < n && nums[idx] < nums[idx + 1])
            idx++;
        if(nums[k] < nums[idx]) {
            swap(nums, k, idx);
            k = idx;
            idx = (k << 1) + 1;
        } else {
            return;
        }
    }
}

void heapSort(int nums[], int lo, int hi) {
    for(int i = hi >> 1; i > -1; i--) {
        siftHeap(nums, i, hi);
    }
    for(int i = lo; i <= hi - 1; i++) {
        swap(nums, lo, hi - i);
        siftHeap(nums, lo, hi - i - 1);
    }
}

int main() {
    int size;
    int* nums;
    cout << "The size of nums: ";
    cin >> size;
    nums = new int[size];
    for(int i = 0; i < size; i++) {
        cout << "The number: ";
        cin >> nums[i];
    }
    heapSort(nums, 0, size -1);
    for(int i = 0; i < size; i++) {
        cout << nums[i] << "\t";
    }
    return 0;
}
