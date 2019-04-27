#include <iostream>
using namespace std;

void swap(int nums[], int a, int b) {
    nums[a] += nums[b];
    nums[b] = nums[a] - nums[b];
    nums[a] -= nums[b];
}

void insertSort(int nums[], int lo, int hi) {
    int idx = 1;
    for(; idx <= hi; idx++) {
        for(int j = idx - 1; j >= lo; j --) {
            if(nums[j] > nums[j + 1]) {
                swap(nums, j, j + 1);
            } else {
                break;
            }
        }
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
    insertSort(nums, 0, size -1);
    for(int i = 0; i < size; i++) {
        cout << nums[i] << "\t";
    }
    return 0;
}
