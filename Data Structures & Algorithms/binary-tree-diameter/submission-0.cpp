/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int diameterHelper(TreeNode* root, int& longestRoute)
    {
        if (!root) return -1;
        if (!root->left && !root->right) return 0;

        int res1 = 1 + diameterHelper(root->left, longestRoute);
        int res2 = 1 + diameterHelper(root->right, longestRoute);

        if (res1 + res2 > longestRoute) longestRoute = res1 + res2;

        return max(res1, res2);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int result = 0;
        diameterHelper(root, result);
        return result;
    }
};
