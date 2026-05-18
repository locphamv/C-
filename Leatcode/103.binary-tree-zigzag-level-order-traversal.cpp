/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
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
class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root == nullptr)
        {
            return ans;
        }
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> tmp;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *p = q.front();
                q.pop();
                tmp.push_back(p->val);

        
                    if (p->left)
                    {
                        q.push(p->left);
                    }
                    if (p->right)
                    {
                        q.push(p->right);
                    }
                
            }
            if(level%2!=0)
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            level++;
        }
        return ans;
    }
};
// @lc code=end
