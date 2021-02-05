#include "string"
#include "iostream"
using namespace std;
class Solution
{
public:
    int minPartitions_1689(string n)
    {
        char max = '1';
        int length = n.length();
        for (int i = 0; i < length; i++)
        {
            if (n[i] > max)
            {
                max = n[i];
                if (max == '9')
                    return 9;
            }
        }
        return max - '0';
    }
};

int main()
{
}