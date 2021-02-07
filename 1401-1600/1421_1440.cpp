//
// Created by Pochita on 2021/2/6.
//
#include "vector"
using namespace std;
class Solution {
public:
    int maxScore_1423(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        int maxSum = sum;
        int length = cardPoints.size();
        for (int i = k - 1; i >= 0; --i) {
            sum = sum - cardPoints[i] + cardPoints[length - (k - i)];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
