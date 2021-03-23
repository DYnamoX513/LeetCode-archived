#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit_188(int k, vector<int> &prices) {
        if (k < 1 || prices.size() < 2)
            return 0;
        int length = 2 * k + 1;
        vector<int> dp(length);
        for (int i = 0; i < k; i++) {
            dp[2 * i + 1] = -prices[0];
        }

        // n. 1~k
        // 0: nothing
        // 2n-1: keep one stock and have already completed n transaction(s)
        // 2n: have already completed (n+1) transaction(s)
        int priceLength = prices.size();
        for (int j = 1; j < priceLength; j++) {
            for (int i = 1; i < length; i++) {
                dp[i] = max(dp[i], dp[i - 1] - prices[j]);
                i++;
                dp[i] = max(dp[i], dp[i - 1] + prices[j]);
            }
        }
        return dp.back();
    }

    void rotate_189(vector<int> &nums, int k) {
        int count = 0;
        int length = nums.size();
        if (!k || k == length)
            return;
        int start = -1;
        while (count != length) {
            start++;
            int i = start;
            int last = nums[start];
            do {
                i = (i + k) % length;
                swap(nums[i], last);
                count++;
            } while (i != start);
        }
    }

    int hammingWeight_191(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result += n & 0b1;
            n >>= 1;
        }
        return result;
        //optimization: n & (n - 1)
    }
};
