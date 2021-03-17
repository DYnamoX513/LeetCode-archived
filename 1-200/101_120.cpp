//
// Created by Pochita on 2021/3/17.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct_115(string s, string t) {
        int sLength = s.length(), tLength = t.length();
        if (sLength < tLength) return 0;
        vector<vector<int>> dp(tLength, vector<int>(sLength + 1, 0));
        for (int i = 1; i <= sLength; ++i) {
            char fromS = s[i - 1];
            dp[0][i] = dp[0][i - 1] + (fromS == t[0]);
            for (int j = 1; j < tLength; ++j) {
                dp[j][i] = dp[j][i - 1] + (fromS == t[j]) * dp[j - 1][i - 1];
            }
        }
        return dp.back().back();
    }
};

int main() {
    Solution s;
    s.numDistinct_115("rarabbiit",
                      "rabbit");
}