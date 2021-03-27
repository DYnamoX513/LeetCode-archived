//
// Created by Pochita on 2021/3/18.
//
#include <ListNode.h>
#include <stack>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates_81(ListNode* head) {
        if (head == nullptr) return head;
        auto ptr = head->next, last = head;
        while (ptr != nullptr) {
            if (ptr->val == last->val) {
                last->next = ptr->next;
//                delete ptr;
                ptr = last->next;
            } else {
                last = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }

    ListNode* deleteDuplicates_82(ListNode* head) {
        if (head == nullptr) return head;
        auto beforeHead = new ListNode(0, head), ptr = head, last = beforeHead;
        int lastVal;
        while (ptr->next != nullptr) {
            if (ptr->val != ptr->next->val) {
                last = ptr;
                ptr = ptr->next;
            } else {
                lastVal = ptr->val;
                while (ptr != nullptr && ptr->val == lastVal) {
                    auto toDelete = ptr;
                    ptr = ptr->next;
                    delete toDelete;
                }
                last->next = ptr;
                if (ptr == nullptr) break;
            }
        }
        auto ret = beforeHead->next;
        delete beforeHead;
        return ret;
    }

    ListNode *reverseBetween_92(ListNode *head, int left, int right) {
        if (left == right) return head;
        auto beforeHead = new ListNode(0, head), ptr = beforeHead;
        int count = 1;
        while (count < left) {
            ptr = ptr->next;
            count++;
        }
        //ptr point to the node at left - 1 (beforeHead if left is 1)
        auto middleHead = ptr, last = ptr->next;
        ptr = last->next;
        //move (right - left) time(s)
        while (count < right) {
            //put ptr next to middleHead, move last and ptr forward
            last->next = ptr->next;
            ptr->next = middleHead->next;
            middleHead->next = ptr;
            ptr = last->next;
            count++;
        }
        //ptr point to the node at right + 1
        return beforeHead->next;
    }
};

int main() {
    Solution s;
    auto li = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    s.reverseBetween_92(li, 2, 4);
}