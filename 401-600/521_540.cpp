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
};