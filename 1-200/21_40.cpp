//
// Created by Pochita on 2021/3/1.
//
#include <algorithm>
#include <ListNode.h>
#include <map>
#include <vector>
#include <stack>
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

    //map内部为红黑树
    //优先队列(priority queue)，内部结构为堆，维护最多k个最前面的节点，每次出队一个最小的节点
    ListNode* mergeKLists_23(vector<ListNode*>& lists) {
        //将所有节点按值大小分组排列，再依次连接起来
        map<int, ListNode *> orderedByVal;
        map<int, ListNode *> heads;
        for (auto list:lists) {
            while (list) {
                auto ptr = list;
                list = list->next;
                auto exist = orderedByVal.find(ptr->val);
                if (exist == orderedByVal.end()) {
                    orderedByVal[ptr->val] = ptr;
                    heads[ptr->val] = ptr;
                } else {
                    exist->second->next = ptr;
                    exist->second = ptr;
                }
                ptr->next = nullptr;
            }
        }
        if (orderedByVal.empty()) return nullptr;
        auto iter = orderedByVal.begin();
        while (true) {
            auto ptr = iter->second;
            if (++iter != orderedByVal.end()) ptr->next = heads[iter->first];
            else break;
        }

        return heads.begin()->second;
    }

    ListNode* swapPairs_24(ListNode* head) {
        if (head == nullptr) return head;
        auto ptr1 = head, ptr2 = ptr1->next;
        if (ptr2 == nullptr) return head;
        auto newHead = new ListNode(0, head), pre = newHead;
        while (ptr1 && ptr2) {
            pre->next = ptr2;
            pre = ptr1;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr1->next;
            if (ptr1) ptr2 = ptr1->next;
        }

        return newHead->next;
    }

    //使用了栈，空间O(k)
    ListNode* reverseKGroup_25(ListNode* head, int k) {
        if (k == 1 || head == nullptr || head->next == nullptr) return head;
        stack<ListNode *> st;
        auto newHead = new ListNode(0), pre = newHead, ptr = head;
        while (true) {
            pre->next = ptr;
            for (int i = 0; i < k; ++i) {
                if (ptr == nullptr) return newHead->next;
                st.push(ptr);
                ptr = ptr->next;
            }
            while (!st.empty()) {
                pre->next = st.top();
                pre = st.top();
                st.pop();
            }
        }
    }

    //空间O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == nullptr || head->next == nullptr) return head;
        auto reverse = [](ListNode *h, ListNode *t) {
            ListNode *ptr;
            while (h != t) {
                ptr = h;
                h = h->next;
                ptr->next = t->next;
                t->next = ptr;
            }
        };
        auto newHead = new ListNode(0, head), h = newHead, t = h;
        while (true) {
            for (int i = 0; i < k; ++i) {
                if (t->next == nullptr) return newHead->next;
                t = t->next;
            }
            auto reverseHead = h->next;
            reverse(reverseHead, t);
            h->next = t;
            h = t = reverseHead;
        }
    }

    int removeDuplicates_26(vector<int>& nums) {
        int count = 0, length = nums.size(), pre = INT32_MAX;
        for (int i = 0; i < length; ++i) {
            if (nums[i] != pre) {
                pre = nums[i];
                nums[count] = pre;
                count++;
            }
        }
        return count;
    }

    int removeElement_27(vector<int>& nums, int val) {
        int length = nums.size(), i = 0, j = length - 1;
        if (length == 0) return 0;
        while (i <= j) {
            if (nums[i] == val) {
                nums[i] = nums[j];
                j--;
            } else
                i++;
        }
        return j + 1;
    }

    int strStr_28(string haystack, string needle) {
        int nLength = needle.length();
        if (nLength == 0) return 0;
        int hLength = haystack.length();
        if (hLength < nLength) return -1;

        for (int i = 0, j = nLength - 1; j < hLength; ++i, ++j) {
            bool flag = true;
            for (int k = 0; k < nLength; ++k) {
                if (haystack[i + k] != needle[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<ListNode *> k({new ListNode(1,new ListNode(2)), new ListNode(2,new ListNode(3))});
    s.mergeKLists_23(k);
//    s.generateParenthesis_22(3);
}

