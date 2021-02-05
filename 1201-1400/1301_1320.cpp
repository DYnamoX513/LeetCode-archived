// using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int deepestLeavesSum_1302(TreeNode *root)
    {
        sum = 0;
        maxDepth = 0;
        search_1302(root, 1);
        return sum;
    }

    void search_1302(TreeNode *node, int depth)
    {
        if (node == nullptr)
        {
            return;
        }
        if (depth > maxDepth)
        {
            maxDepth = depth;
            sum = node->val;
        }
        else if (depth == maxDepth)
        {
            sum += node->val;
        }

        search_1302(node->left, depth + 1);
        search_1302(node->right, depth + 1);
    }

private:
    int sum;
    int maxDepth;
};