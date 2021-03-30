//
// Created by Pochita on 2021/3/28.
//
#include <vector>
#include <TreeNode.h>

using namespace std;

//No.173
class BSTIterator {
private:
    vector<int> nodes;
    int length, index = 0;

    void visit(TreeNode *node) {
        if (node == nullptr) return;
        visit(node->left);
        nodes.emplace_back(node->val);
        visit(node->right);
    }

public:
    explicit BSTIterator(TreeNode *root) {
        visit(root);
        length = nodes.size();
    }

    int next() {
        return nodes[index++];
    }

    bool hasNext() const {
        return index < length;
    }
};
