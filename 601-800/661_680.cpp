//
// Created by Pochita on 2021/2/7.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strangePrinter_664(string s) {
        int length = s.length();
        vector<vector<int>> dp(length, vector<int>(length));
        for (int i = length - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < length; ++j) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i][j - 1];
                else {
                    int m = INT32_MAX;
                    for (int k = i; k < j; ++k)
                        m = min(m, dp[i][k] + dp[k + 1][j]);
                    dp[i][j] = m;
                }
            }
        }
        return dp[0][length - 1];
    }

    bool checkPossibility_665(vector<int> &nums) {
        int length = static_cast<int>(nums.size()) - 1;
        bool flag = false;
        int lastAdjust = 0;
        for (int i = 0; i < length; ++i) {
            //先尝试 将前一个调整到更前一个的值（调小，不会影响之后的比较结果）
            //若仍不满足递增，再尝试 将后一个调整到前一个的值（调大，会影响更后一个比较的结果）
            if (nums[i] > nums[i + 1]) {
                if (flag) {
                    return false;
                } else if (i != 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                }
                flag = true;
            }
        }
        return true;
    }
};