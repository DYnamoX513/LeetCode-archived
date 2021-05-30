//
// Created by Pochita on 2021/3/23.
//
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minChanges_1787(vector<int>& nums, int k) {
        // https://leetcode-cn.com/problems/make-the-xor-of-all-segments-equal-to-zero/solution/shi-suo-you-qu-jian-de-yi-huo-jie-guo-we-uds2/
        int max_change = 2000;
        int max_x = 1 << 10;
        int length = nums.size();
        vector<int> dp(max_x, max_change);
        dp[0] = 0;

        for (int i = 0; i < k; i++) {
            int size = (length - i - 1) / k + 1;
            unordered_map<int, int> count;
            for (int j = i; j < length; j += k) ++count[nums[j]];

            int lastMin = *min_element(dp.begin(), dp.end());
            vector<int> newDp(max_x, lastMin);
            for (int k = 0; k < max_x; k++)
                for (auto [n, c] : count)
                    newDp[k] = min(newDp[k], dp[n ^ k] - c);

            for (int& d : newDp) d += size;
            dp = move(newDp);
        }

        return dp[0];
    }

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