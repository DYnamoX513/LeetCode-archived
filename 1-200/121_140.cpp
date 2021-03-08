#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit_121(vector<int> &prices) {
        // brute

        // int length = prices.size();
        // int max = 0;
        // for (int i = 0; i < length; i++)
        // {
        //     if (i < length - 1 && prices[i] >= prices[i + 1])
        //         continue;
        //     for (int j = i + 1; j < length; j++)
        //     {

        //         int profit = prices[j] - prices[i];
        //         if (profit > max)
        //         {
        //             max = profit;
        //         }
        //     }
        // }
        // return max;

        int minPrice = INT32_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice)
                minPrice = price;
            else {
                maxProfit = max(price - minPrice, maxProfit);
            }
        }
        return maxProfit;
    }

    int maxProfit_122(vector<int> &prices) {
        int buy = INT32_MAX;
        int sell = buy;
        int sum = 0;
        // guard
        prices.emplace_back(-1);
        for (int price : prices) {
            // 清算
            if (price < sell) {
                sum += sell - buy;
                buy = sell = price;
            } else {
                sell = price;
            }
        }
        return sum;
    }

    int maxProfit_123(vector<int> &prices) {
        int length = prices.size();

        // 一天结束后 的利润　
        // -1    没有股票
        // 0    持有一个
        // 1    交易后没有股票
        // 2    交易后持有一个
        // 3    交易两次后没有股票
        // vector<vector<int>> dp(length, vector<int>(4));
        // dp[0][0] = -prices[0];
        // dp[0][1] = 0;
        // dp[0][2] = -prices[0];
        // dp[0][3] = 0;

        // for (int i = 1; i < length; ++i)
        // {
        //     dp[i][0] = max(dp[i - 1][0], -prices[i]);
        //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        //     dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
        //     dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        // }

        // return dp[length-1][3];

        int status1 = -prices[0], status2 = 0, status3 = -prices[0], status4 = 0;
        for (int i = 1; i < length; ++i) {
            status1 = max(status1, -prices[i]);
            status2 = max(status2, status1 + prices[i]);
            status3 = max(status3, status2 - prices[i]);
            status4 = max(status4, status3 + prices[i]);
        }
        return status4;
    }

    vector<vector<string>> partition_131(string s) {
        // dp_131[i][j]
        // = 1 (i==j)
        // = s[i]==s[j] (i+1==j)
        // = dp_131[i+1][j-1] && s[i]==s[j] (i+1<j)
        length_131 = s.length();
        dp_131.assign(length_131, vector<bool>(length_131, true));
        for (int i = length_131 - 1; i >= 0; --i) {
            for (int j = i + 1; j < length_131; ++j) {
                dp_131[i][j] = s[i] == s[j] && dp_131[i + 1][j - 1];
            }
        }
        dfs_131(0, s);
        return result_131;
    }

    vector<vector<bool>> dp_131;
    vector<vector<string>> result_131;
    vector<string> sequence_131;
    int length_131 = 0;

    void dfs_131(int start, const string &s) {
        if (start == length_131)
            result_131.push_back(sequence_131);
        sequence_131.emplace_back("");
        for (int i = start; i < length_131; ++i) {
            if (dp_131[start][i]) {
                sequence_131.back() = s.substr(start, i - start + 1);
                dfs_131(i + 1, s);
            }
        }
        sequence_131.pop_back();
    }

    int minCut_132(string s) {
        int length = s.length();
        vector<vector<bool>> dp(length, vector<bool>(length, true));
        for (int i = length - 1; i >= 0; --i) {
            for (int j = i + 1; j < length; ++j) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
        }
        vector<int> cuts(length, INT32_MAX);
        for (int i = 0; i < length; ++i) {
            if (dp[0][i]) cuts[i] = 0;
            else {
                for (int j = 1; j <= i; ++j) {
                    if (dp[j][i])
                        cuts[i] = min(cuts[i], cuts[j-1] + 1);
                }
            }
        }
        return cuts[length - 1];
    }
};

int main() {
    Solution s;
    s.minCut_132("cabababcbc");
//    vector<int> test{1, 2};
//    s.maxProfit_123(test);
}