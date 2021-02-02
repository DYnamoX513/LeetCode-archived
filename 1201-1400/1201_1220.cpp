#include "iostream"
#include "map"
#include "string"
#include "../utils/DisjointSet.h"
using namespace std;
class Solution
{
public:
    string smallestStringWithSwaps_1202(string s, vector<vector<int>> &pairs)
    {
        int length = s.length();
        if (length < 2 || pairs.size() < 1)
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
            sort(set.second.begin(), set.second.end(), greater<int>());
        }
        for (int i = 0; i < length; i++)
        {
            int find = djs.findParent(i);
            s[i] = sets[find].back();
            sets[find].pop_back();
        }

        return s;
    }    
};

int main()
{
    Solution s;
    vector<vector<int>> pairs;
    pairs.emplace_back(vector<int>{14,19});
    pairs.emplace_back(vector<int>{19,8});
    pairs.emplace_back(vector<int>{22,2});
    pairs.emplace_back(vector<int>{0,7});
    pairs.emplace_back(vector<int>{20,22});
    pairs.emplace_back(vector<int>{11,21});
    pairs.emplace_back(vector<int>{0,2});
    pairs.emplace_back(vector<int>{21,9});
    pairs.emplace_back(vector<int>{18,11});
    pairs.emplace_back(vector<int>{14,17});
    pairs.emplace_back(vector<int>{2,11});
    pairs.emplace_back(vector<int>{19,8});
    pairs.emplace_back(vector<int>{1,0});
    pairs.emplace_back(vector<int>{4,16});
    pairs.emplace_back(vector<int>{15,19});
    pairs.emplace_back(vector<int>{0,14});
    pairs.emplace_back(vector<int>{9,16});
    pairs.emplace_back(vector<int>{9,14});
    pairs.emplace_back(vector<int>{8,15});
    pairs.emplace_back(vector<int>{7,6});
    pairs.emplace_back(vector<int>{11,21});
    pairs.emplace_back(vector<int>{5,15});
    //[[6,6],[5,7],[11,4],[0,0],[6,2],[6,7],[0,7],[4,0],[3,1],[2,9],[4,7],[8,6],[9,0]]
    cout << s.smallestStringWithSwaps_1202("icjkcvebjmuzokbvgusbfgz", pairs) << endl;
}