#include <iostream>
#include <vector>
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

vector<int> rangeSearch(const int nums[], int lo, int hi, int a, int b) {
    vector<int> v;
    int idxL = (nums[lo] >= a) ? lo : binSearch(nums, lo + 1, hi, a);
    if(idxL == -1)
        return v;
    int idxR = (nums[hi] <= b) ? hi : binSearch(nums, idxL, hi, b);
    if(idxR == -1)
        return v;
    while(idxL > lo && nums[idxL] == nums[idxL - 1]) idxL--;
    while(idxR < hi && nums[idxR] == nums[idxR + 1]) idxR++;
    for(; idxL <= idxR; idxL++)
        v.push_back(nums[idxL]);
    return v;
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
    int a;
    cout << "The a is : ";
    cin >> a;
    int b;
    cout << "The b is : ";
    cin >> b;
    vector<int> v = rangeSearch(nums, 0, size - 1, a, b);
    for (int i : v) {
        cout << i << "\t";
    }
    return 0;
}
