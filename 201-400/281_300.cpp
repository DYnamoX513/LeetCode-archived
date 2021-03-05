//
// Created by 段宇昕 on 2021/3/4.
//
#include <vector>
using namespace std;
class Solution {
public:
    //O(n^2)
    int lengthOfLIS_300(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length);
        int result = 0;
        for (int i = 0; i < length; ++i) {
            int maxSub = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j])
                    maxSub = max(maxSub, dp[j] + 1);
            }
            dp[i] = maxSub;
            result = max(maxSub, result);
        }
        return result;
    }
};