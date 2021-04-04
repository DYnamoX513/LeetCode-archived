//
// Created by Pochita on 2021/4/3.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence_1143(string text1, string text2) {
        int length1 = text1.length(), length2 = text2.length();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 1; i <= length1; ++i)
            for (int j = 1; j <= length2; ++j)
                dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        return dp[length1][length2];
    }
};