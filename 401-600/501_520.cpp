#include "iostream"
#include "math.h"
#include "vector"
using namespace std;
class Solution
{
public:
    bool checkPerfectNumber_507(int num)
    {
        if (num % 2 != 0)
            return false;
        int sum = 0;
        for (int i = 1; i * i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;

                if (i * i != num)
                {
                    sum += num / i;
                }
            }
        }
        return sum==2*num;
    }
};

int main()
{
    Solution s;
    cout << s.checkPerfectNumber_507(28) << endl;
    return 0;
}