class Solution {
    int height(TreeNode* root, bool& balanced)
    {
        if (!root) return -1;

        int l = height(root->left, balanced);
        int r = height(root->right, balanced);
        if (abs(l - r) > 1) balanced = false;

        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root)
    {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
};