//
// Created by Pochita on 2021/3/20.
//
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN_150(vector<string>& tokens) {
        stack<int> st;
        int first;
        for (const auto &s : tokens) {
            switch (s[0]) {
                case '*':
                    first = st.top();
                    st.pop();
                    st.top() *= first;
                    break;
                case '/':
                    first = st.top();
                    st.pop();
                    st.top() /= first;
                    break;
                case '+':
                case '-':
                    if (s.length() == 1) {
                        first = st.top();
                        st.pop();
                        st.top() += s[0] == '+' ? first : -first;
                        break;
                    }
                default:
                    st.push(strtol(s.c_str(), nullptr, 10));
            }
        }
        return st.top();
    }
};