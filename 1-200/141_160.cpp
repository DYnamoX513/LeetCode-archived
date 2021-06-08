//
// Created by Pochita on 2021/3/20.
//
#include <ListNode.h>

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

    ListNode *getIntersectionNode_160(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        int count = 0;
        auto ptrA = headA, ptrB = headB;
        for (; ptrA != nullptr; ptrA = ptrA->next) count++;
        for (; ptrB != nullptr; ptrB = ptrB->next) count--;
        for (; count > 0; count--) headA = headA->next;
        for (; count < 0; count++) headB = headB->next;
        for (; headA != headB; headA = headA->next, headB = headB->next)
            ;
        return headA;

        // Precise
        /*
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
         */
    }
};