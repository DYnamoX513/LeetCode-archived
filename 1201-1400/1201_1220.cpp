#include <map>
#include <string>
#include <DisjointSet.h>

#if defined(_WIN32)
#include <algorithm>
#endif

using namespace std;
class Solution
{
public:
    string smallestStringWithSwaps_1202(string s, vector<vector<int>> &pairs)
    {
        int length = s.length();
        if (length < 2 || pairs.empty())
            return s;
        // [1,2] [2,3] => [1,2,3]
        // [1,2] [1,3] => [1,2,3]
        DisjointSet djs(length);
        for (auto &pair : pairs)
        {
            djs.merge(pair[0], pair[1]);
        }
        map<int, vector<int>> sets;
        for (int i = 0; i < length; i++)
        {
            sets[djs.findParent(i)].emplace_back(s[i]);
        }
        for(auto &set:sets){
            sort(set.second.begin(), set.second.end(), greater<>());
        }
        for (int i = 0; i < length; i++)
        {
            int find = djs.findParent(i);
            s[i] = sets[find].back();
            sets[find].pop_back();
        }

        return s;
    }

    int equalSubstring_1208(string s, string t, int maxCost) {
        int length = s.length();
        int maxCount = 0, accumulate = 0;
        //maxCount为滑动窗口的长度
        for (int i = 0; i < length; ++i) {
            if ((accumulate += abs(s[i] - t[i])) <= maxCost) {
                maxCount++;
            } else {
                //移动该窗口直到有更大的窗口出现
                accumulate -= abs(s[i - maxCount] - t[i - maxCount]);
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution s;
//    cout << s.equalSubstring_1208("ujteygggjwxnfl",
//                                  "nstsenrzttikoy",43) << endl;
//
//    cout << s.equalSubstring_1208("abcd",
//                                  "adef",0) << endl;
}