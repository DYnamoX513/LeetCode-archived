//
// Created by Pochita on 2021/3/24.
//
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern_456(vector<int>& nums) {
        int length = nums.size();
        if (length < 3) return false;
        stack<int> decreasing({nums[length - 1]});
        int second = INT32_MIN;
        for (int i = length - 2; i >= 0; --i) {
            int judge = nums[i];
            if (judge < second) return true;
            while (!decreasing.empty() && judge > decreasing.top()) {
                second = decreasing.top();
                decreasing.pop();
            }
            //防止judge == second入栈，此judge不会帮助second更新为更大的值
            if (judge > second) decreasing.push(judge);
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> vec({3, 5, 0, 3, 4});
    s.find132pattern_456(vec);
}