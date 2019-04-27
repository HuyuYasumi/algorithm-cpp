#include <iostream>
using namespace std;

int binSearch(const int nums[], int lo, int hi, int target) {
    int min = (lo + hi) >> 1;
    for(int i = lo, j = hi; i <= j; min = (i + j) >> 1) {
        if(target > nums[min])
            i = min + 1;
        else if(target < nums[min])
            j = min - 1;
        else
            return min;
    }
    return -1;
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
    int target;
    cout << "The target is : ";
    cin >> target;
    cout << "The idx is:" << binSearch(nums, 0, size - 1, target);
    return 0;
}
