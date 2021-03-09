//
// Created by Pochita on 2021/3/9.
//
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates_1047(string s) {
        //题解用栈速度更快，时间O(n)，空间O(n)
        //string res; 用string模拟栈pop_back,push_back
        int i = 0, j = 1;
        while (j < s.length()) {
            int length = s.length();
            while (i >= 0 && j < length && s[i] == s[j]) {
                i--;
                j++;
            }
            s.erase(i + 1, j - i - 1);
            if (i < 0) i = 0;
            j = i + 1;
        }
        return s;
    }
};
