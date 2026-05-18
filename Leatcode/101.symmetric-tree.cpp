/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isPalindrome(const vector<int> &a)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            vector<int> tmp;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {

                TreeNode *p = q.front();
                q.pop();
                if (p == nullptr)
                {
                    tmp.push_back(101);
                    continue;
                }

                tmp.push_back(p->val);

                q.push(p->left);

                q.push(p->right);
            }

            if (!isPalindrome(tmp))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
