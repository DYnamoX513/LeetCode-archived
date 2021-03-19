//
// Created by Pochita on 2021/3/1.
//
#include <algorithm>
#include <ListNode.h>
#include <map>
#include <unordered_map>
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

    int divide_29(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT32_MIN)
                return INT32_MAX;
            else
                return -dividend;
        }
        int sign = (dividend ^ divisor) < 0 ? -1 : 1;
        long remain = abs(static_cast<long>(dividend)), di = abs(static_cast<long>(divisor));
        int result = 0;
        for (int i = 30; i >= 0; --i) {
            if ((di << i) <= remain) {
                remain -= di << i;
                result += i << i;
            }
        }
        return sign * result;
    }

    vector<int> findSubstring_30(string s, vector<string>& words) {
        int sLength = s.length(), wLength = words.size(), length = words[0].length();
        vector<int> result;
        sLength -= wLength * length;
        if (sLength < 0) return result;
        unordered_map<string, int> wordCount;
        for (const auto &word : words) {
            auto iter = wordCount.find(word);
            if (iter == wordCount.end())
                wordCount[word] = 1;
            else
                iter->second++;
        }
        vector<int *> w;
        for (int i = 0; i <= sLength; ++i) {
            for (int j = 0; j < wLength; ++j) {
                auto iter = wordCount.find(s.substr(i + length * j, length));
                if (iter == wordCount.end() || iter->second == 0)
                    break;
                else {
                    w.emplace_back(&(iter->second));
                    iter->second--;
                }
            }
            int count = w.size();
            if (count == wLength) result.emplace_back(i);
            for (int j = 0; j < count; ++j)
                (*w[j])++;
            w.clear();
        }
        return result;
    }

    void nextPermutation_31(vector<int>& nums) {
        int length = nums.size(), index = length - 2;
        /*vector<int> increase;
        increase.push_back(nums.back());

        while (index >= 0) {
            int num = nums[index];
            if (num >= increase.back())
                increase.emplace_back(num);
            else {
                auto larger = upper_bound(increase.begin(), increase.end(), num);
                if (larger != increase.end())
                    swap(*larger, nums[index]);
                break;
            }
            index--;
        }
        for (int i : increase)
            nums[++index] = i;*/

        //不开辟额外的空间
        while (index >= 0 && nums[index] >= nums[index + 1]) {
            index--;
        }
        if (index >= 0) {
            auto larger = lower_bound(nums.begin() + index + 1, nums.end(), nums[index], greater<>());
            swap(*(larger - 1), nums[index]);
        }
        reverse(nums.begin() + index, nums.end());
    }

    int longestValidParentheses_32(string s) {
        short length = s.length();
        if (length < 2) return 0;
        int result = 0;
        stack<short> st;
        st.push(-1);
        for (short i = 0; i < length; ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    result = max(i - st.top(), result);
            }
        }
        return result;
    }

    //不开辟额外的空间
    int longestValidParentheses_noExtraSpace(string s) {
        int length = s.length();
        if (length < 2) return 0;
        int result = 0, left = 0, right = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] == '(') left++;
            else right++;
            if (right > left) {
                right = left = 0;
            } else if (right == left) {
                result = max(result, right + left);
            }
        }
        right = left = 0;
        for (int i = length - 1; i >= 0; --i) {
            if (s[i] == '(') left++;
            else right++;
            if (right < left) {
                right = left = 0;
            } else if (right == left) {
                result = max(result, right + left);
            }
        }
        return result;
    }

    int searchInsert_35(vector<int>& nums, int target) {
        //STL一行代码
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        //二分法
        /*int l = 0, r = static_cast<int>(nums.size()) - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;*/
    }
};

int main(){
    Solution s;
    s.longestValidParentheses_32("(((())()()))()(())");
//    vector<string> st({"word","good","best","good"});
//    s.findSubstring_30("wordgoodgoodgoodbestword"
//                    , st);
//    s.divide_29(10,3);
//    vector<int> nextP({1,2,3,2});
//    s.nextPermutation_31(nextP);
//    vector<ListNode *> k({new ListNode(1,new ListNode(2)), new ListNode(2,new ListNode(3))});
//    s.mergeKLists_23(k);
//    s.generateParenthesis_22(3);
}

