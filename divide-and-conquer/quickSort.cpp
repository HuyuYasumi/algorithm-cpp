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

int main() {
    int nums[] = {4, 3, 8, 3, 5};
    int nums2[] = {6, 4, 3, 1, 1, -3};
    QuickSort(nums2, 0, 5);
    QuickSort(nums, 0, 4);
    return 0;
}
