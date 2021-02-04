#include "map"
#include "vector"
#include "string"
#include "iostream"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> twoSum_1(vector<int> &nums, int target)
    {
        map<int, int> remainAndIndex;
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            auto iter = remainAndIndex.find(nums[i]);
            if (iter != remainAndIndex.end())
            {
                return {iter->second, i};
            }
            else
            {
                remainAndIndex[target - nums[i]] = i;
            }
        }
        return {};
    }

    ListNode *addTwoNumbers_2(ListNode *l1, ListNode *l2)
    {
        auto *newList = new ListNode();
        ListNode *pointer = newList;
        int val1, val2, carry = 0;
        while (l1 || l2)
        {
            if (l1 != nullptr)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            else
            {
                val1 = 0;
            }

            if (l2 != nullptr)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            else
            {
                val2 = 0;
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            pointer->next = new ListNode(sum % 10);
            pointer = pointer->next;
        }
        if (carry > 0)
        {
            pointer->next = new ListNode(0);
        }
        return newList->next;
    }

    string longestPalindrome_5(string s)
    {
        //中心扩散
        int length = s.length();
        if (length < 2)
        {
            return s;
        }
        int previous = 0, next = 0, longest = 0, position = 0;
        //是否判断过回文长度为偶数，true=未判断
        bool flag = true;
        for (int i = 0; i < length - 1; i++)
        {
            while (previous >= 0 && next < length && s[previous] == s[next])
            {
                previous--;
                next++;
            }
            int len = next - previous - 1;
            if (len > longest)
            {
                longest = len;
                position = previous + 1;
            }

            previous = next = i + 1;
            // 对每个中心位置，先检查以自身为中心的回文字串，再检查以自身和下一个（若可能）为中心的回文字串
            if (flag && s[i] == s[i + 1])
            {
                previous--;
                i--;
                flag = false;
            }
            else
            {
                flag = true;
            }
        }
        return s.substr(position, longest);
    }

    int reverse_7(int x) {
        /*int sign = x > 0 ? 1 : -1;
        if (x == 0)
            return 0;
        string original = to_string(x);
        string reversed;
        int count = (int) original.length() - 1;
        while (original[count] == '0')
            count--;
        while (count >= 0) {
            reversed += original[count];
            count--;
        }
        try {
            return stoi(reversed) * sign;
        } catch (exception &) {
            return 0;
        }*/

        // Official Solution (Better)
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{
    Solution s;
//    s.addTwoNumbers_2(new ListNode(2), new ListNode(5, new ListNode(1)));
//    cout << s.longestPalindrome_5("ababa") << endl;
    cout << s.reverse_7(1534236469) << endl;
    cout << -123 % 10;
}