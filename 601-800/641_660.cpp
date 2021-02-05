//
// Created by Pochita on 2021/2/4.
//
#include "vector"

using namespace std;

class Solution {
public:
    double findMaxAverage_643(vector<int> &nums, int k) {
        int sum = 0;
        int length = nums.size();
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double result = (double) sum / k;
        for (int i = k; i < length; ++i) {
            sum += nums[i] - nums[i - k];
            result = max(result, (double) sum / k);
        }
        return result;
    }
};

int main() {
    Solution s;
    int array[6] = {1, 12, -5, -6, 50, 3};
    vector<int> test(array, &array[6]);
    s.findMaxAverage_643(test, 4);
}