//
// Created by Pochita on 2021/3/1.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //LEETCODE_LISTNODE_H
