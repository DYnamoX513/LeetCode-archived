//
// Created by Pochita on 2021/3/1.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif //LEETCODE_TREENODE_H
