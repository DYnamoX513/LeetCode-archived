//
// Created by Pochita on 2021/2/7.
//
#include <vector>
using namespace std;
class Solution {
public:
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