class Solution {
    int height(TreeNode* root, int& best)
    {
        if (!root) return -1;

        int l = 1 + height(root->left, best);
        int r = 1 + height(root->right, best);
        best = max(best, l + r);

        return max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int result = 0;
        height(root, result);
        return result;
    }
};