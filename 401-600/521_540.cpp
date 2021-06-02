#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum_523(vector<int>& nums, int k) {
        unordered_map<int, int> mod;
        int sum = nums[0] % k;
        mod[sum] = 1;
        int length = nums.size();
        for (int i = 1; i < length; ++i) {
            sum += nums[i];
            sum %= k;
            if (sum == 0) return true;
            if (mod.count(sum)) {
                int m = mod[sum];
                if (i > m) return true;
            } else
                mod[sum] = i + 1;
        }
        return false;
    }

    int findMaxLength_525(vector<int>& nums) {
        // number of 0 - number of 1
        unordered_map<int, int> difference;
        int maxLength = 0, count = 0, length = nums.size();
        for (int i = 0; i < length; ++i) {
            count += nums[i];
            int zeroMinusOne = i - count - count + 1;
            if (zeroMinusOne == 0)
                maxLength = i + 1;
            else if (difference.count(zeroMinusOne))
                maxLength = max(maxLength, i - difference[zeroMinusOne]);
            else
                difference[zeroMinusOne] = i;
        }
        return maxLength;
    }
};