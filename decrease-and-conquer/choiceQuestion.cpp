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

int selectionQuestion(int nums[], int lo, int hi, int k) {
    if(k > hi || k < lo)
        return NULL;
    int idx = Partition(nums, lo, hi);
    if(k == idx)
        return nums[idx];
    else if(k < idx)
        return selectionQuestion(nums, lo, idx - 1, k);
    else
        return selectionQuestion(nums, idx + 1, hi, k);
}

int main() {
    int size;
    int* nums;
    int k;
    cout << "The size of nums: ";
    cin >> size;
    nums = new int[size];
    for(int i = 0; i < size; i++) {
        cout << "The number: ";
        cin >> nums[i];
    }
    cout << "The k: ";
    cin >> k;
    cout << "The result of selection: ";
    cout << selectionQuestion(nums, 0, size - 1, k);
    return 0;
}
