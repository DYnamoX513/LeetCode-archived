//
// Created by Pochita on 2021/3/23.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum_1800(vector<int> &nums) {
        int length = nums.size(), result = 0, sum = 0, previous = 0;
        for (int i = 0; i < length; ++i) {
            if (nums[i] > previous) {
                previous = nums[i];
                sum += previous;
            } else {
                previous = nums[i];
                result = max(sum, result);
                sum = previous;
            }
        }
        return max(sum, result);
    }
};