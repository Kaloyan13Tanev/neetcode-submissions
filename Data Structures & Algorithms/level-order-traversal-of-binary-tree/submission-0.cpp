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
    void bfs(TreeNode* root, vector<vector<int>>& res)
    {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                level.push_back(q.front()->val);
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            res.push_back(level);
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        bfs(root, result);
        return result;
    }
};