#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges_228(vector<int> &nums)
    {
        vector<string> result;
        int length = nums.size();
        if (length == 0)
            return result;
        int record = 0;
        for (int i = 0; i < length; i++)
        {
            if (i + 1 == length || nums[i + 1] != 1 + nums[i])
            {
                if (record == i)
                    result.emplace_back(to_string(nums[record]));
                else
                    result.emplace_back(to_string(nums[record]) + "->" + to_string(nums[i]));
                record = i + 1;
            }
        }

        return result;
    }
};

int main()
{
}