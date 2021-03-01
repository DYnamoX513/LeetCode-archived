//
// Created by Pochita on 2021/3/1.
//
#include "vector"
using namespace std;

//No.303
class NumArray {
public:
    int *sums;

    explicit NumArray(vector<int> &nums) {
        int length = nums.size();
        sums = new int[length + 1];
        int sum = sums[0] = 0;
        for (int i = 0; i < length; ++i) {
            sums[i + 1] = sum += nums[i];
        }
    }

    int sumRange(int i, int j) const {
        return sums[j + 1] - sums[i];
    }
};

class Solution {
public:

};