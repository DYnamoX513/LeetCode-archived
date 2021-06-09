//
// Created by Pochita on 2021/2/25.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose_867(vector<vector<int>>& matrix) {
        int column = matrix[0].size();
        int row = matrix.size();
        vector<vector<int>> result(column, vector<int>(row));
        for (int i = 0; i < column; ++i) {
            for (int j = 0; j < row; ++j) {
                result[i][j] = matrix[j][i];
            }
        }
        return result;
    }

    int profitableSchemes_879(int n, int minProfit, vector<int>& group,
                              vector<int>& profit) {
        // dp[i][j][k],前i个达到profit >= j,number <= k 有几种方案
        // dp[i+1][j][k] = dp[i][j][k]+dp[i][j-pro][k-num]
        // j-pro<0时，取dp[i][0][k-num]
        // 初始化，j=0时，什么都不选=1种情况
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        int length = group.size();
        for (int i = 0; i < length; i++) {
            int num = group[i], pro = profit[i];
            for (int j = minProfit; j >= 0; j--) {
                int requireProfit = max(j - pro, 0);
                for (int k = n; k >= num; k--) {
                    dp[j][k] =
                        (dp[j][k] + dp[requireProfit][k - num]) % 1000000007;
                }
            }
        }
        return dp[minProfit][n];
    }
};