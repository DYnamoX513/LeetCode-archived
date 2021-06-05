//
// Created by Pochita on 2021/6/6.
//

#include <ListNode.h>
//using namespace std;

class Solution {
public:
    ListNode* removeElements_203(ListNode* head, int val) {
        ListNode *pre = new ListNode(0, head), *ptr = pre;
        while(ptr->next != nullptr) {
            if(ptr->next->val == val)
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        auto result = pre->next;
        delete pre;
        return result;
    }
};