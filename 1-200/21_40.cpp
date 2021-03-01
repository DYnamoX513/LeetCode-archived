//
// Created by Pochita on 2021/3/1.
//
#include <ListNode.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists_21(ListNode *l1, ListNode *l2) {
        auto ptr1 = l1, ptr2 = l2, pre = new ListNode(), ptrNew = pre;
        while (ptr1 && ptr2) {
            if (ptr1->val > ptr2->val) {
                ptrNew = ptrNew->next = ptr2;
                ptr2 = ptr2->next;
            } else {
                ptrNew = ptrNew->next = ptr1;
                ptr1 = ptr1->next;
            }
        }
        if (ptr1 != nullptr)
            pre->next = ptr1;
        else
            pre->next = ptr2;

        return pre->next;
    }

    vector<string> generateParenthesis_22(int n) {
        vector<string> result;
        generate(result, "", n, n);
        return result;
    }

    void generate(vector<string> &strings, const string &s, int left, int right) {
        if (left == 0 && right == 0) {
            strings.emplace_back(s);
        } else {
            if (left < right)
                generate(strings, s + ')', left, right - 1);
            if (left > 0)
                generate(strings, s + '(', left - 1, right);
        }
    }
};

int main(){
    Solution s;
    s.generateParenthesis_22(3);
}
