//
// Created by 段宇昕 on 2021/2/27.
//
#include "vector"
#include "string"
#include "unordered_map"
#include "iostream"
using namespace std;
class Solution {
public:
    int longestSubstring_395(const string& s, int k) {
        return longestSubstring_recursive(s,0,s.length(),k,0);
    }

    int longestSubstring_recursive(const string& s, int begin, int end, int k, int maxSub) {
        int length = end - begin;
        if (length < maxSub || length < k) return maxSub;
        unordered_map<char, vector<int>> charMap;
        for (int i = begin; i < end; ++i) {
            charMap[s[i]].push_back(i);
        }
        auto iter = charMap.begin();
        bool cut = false;
        while (iter != charMap.end()) {
            int count = iter->second.size();
            if (count < k) {
                cut = true;
                maxSub = longestSubstring_recursive(s, begin, iter->second.front(), k, maxSub);
                for (int i = 1; i < count; ++i) {
                    maxSub = longestSubstring_recursive(s, iter->second[i - 1] + 1, iter->second[i], k, maxSub);
                }
                maxSub = longestSubstring_recursive(s, iter->second.back() + 1, end, k, maxSub);
                break;
            }
            iter++;
        }

        if (!cut) maxSub = max(maxSub, length);
        return maxSub;
    }
};

int main(){
    Solution s;
    cout<< s.longestSubstring_395("baaabcb",3) <<endl;
}