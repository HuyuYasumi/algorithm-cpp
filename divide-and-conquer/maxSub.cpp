#include <iostream>
using namespace std;

int maxSub(int nums[], int lo, int hi) {
    if(lo == hi)
        return nums[lo];
    int min = (lo + hi) >> 1;
    int leftSum = maxSub(nums, lo, min);
    int rightSum = maxSub(nums, min + 1, hi);

    int sl = nums[min], ms = nums[min];
    for(int i = min - 1; i >= lo; i--) {
        ms += nums[i];
        if(sl < ms)
            sl = ms;
    }
    int sr = ms = nums[min + 1];
    for(int i = min + 2; i <= hi; i++) {
        ms += nums[i];
        if(sr < ms)
            sr = ms;
    }
    ms = sl + sr;

    if(ms < leftSum)
        ms = leftSum;
    if(ms < rightSum)
        ms = rightSum;
    return ms;
}

int main() {
    int nums[] = {-3, 4, 5, -6, 7, 1, -11};
    cout << maxSub(nums, 0, 6);
    return 0;
}
