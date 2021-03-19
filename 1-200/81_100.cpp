//
// Created by Pochita on 2021/3/18.
//
#include <ListNode.h>
#include <stack>

using namespace std;

class Solution {
public:
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
    s.reverseBetween(li, 2, 4);
}