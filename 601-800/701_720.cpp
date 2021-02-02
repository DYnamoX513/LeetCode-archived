#include "iostream"
#include "vector"
using namespace std;

class Solution
{
public:
    int pivotIndex_724(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
        {
            return 0;
        }
        //起始
        int leftSum = 0;
        int rightSum = 0;
        //添加辅助位
        nums.emplace_back(0);
        for (int i = 1; i < length; i++)
        {
            rightSum += nums[i];
        }
        for (int i = 0; i < length; i++)
        {
            if (leftSum == rightSum)
            {
                return i;
            }
            leftSum += nums[i];
            rightSum -= nums[i + 1];
        }
        return -1;
    }
};

int main()
{
}