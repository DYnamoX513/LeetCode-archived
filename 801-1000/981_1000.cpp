//
// Created by Pochita on 2021/2/8.
//
#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int maxTurbulenceSize_978(vector<int>& arr) {
        int length = arr.size();
        if (length < 2) return 1;
        //dp[i][0] = 最大长度，末尾满足arr[i-1]<arr[i]
        //dp[i][1] = 最大长度，末尾满足arr[i-1]>arr[i]
        int dp0 = 1;
        int dp1 = 1;
        int maxInterval = 1;
        for (int i = 1; i < length; ++i) {
            int subtract = arr[i] - arr[i - 1];
            if (subtract < 0) {
                dp1 = dp0 + 1;
                maxInterval = max(maxInterval, dp1);
                dp0 = 1;
            } else if (subtract > 0) {
                dp0 = dp1 + 1;
                maxInterval = max(maxInterval, dp0);
                dp1 = 1;
            } else
                dp0 = dp1 = 1;
        }
        return maxInterval;
    }
};

int main(){
    Solution s;
    vector<int> a({0,8,45,88,48,68,28,55,17,24});
    s.maxTurbulenceSize_978(a);
}