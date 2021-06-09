//
// Created by Pochita on 2021/3/9.
//
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicates_1047(string s) {
        //题解用栈速度更快，时间O(n)，空间O(n)
        //string res; 用string模拟栈pop_back,push_back
        int i = 0, j = 1;
        while (j < s.length()) {
            int length = s.length();
            while (i >= 0 && j < length && s[i] == s[j]) {
                i--;
                j++;
            }
            s.erase(i + 1, j - i - 1);
            if (i < 0) i = 0;
            j = i + 1;
        }
        return s;
    }

    int lastStoneWeightII_1049(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int half = sum / 2;
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        for (int weight : stones)
            for (int i = half; i >= weight; i--)
                dp[i] = dp[i] || dp[i - weight];

        for (int i = half;; i--)
            if (dp[i]) return sum - 2 * i;
    }
};
