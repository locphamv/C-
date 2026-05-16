/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void inOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        if (prev != nullptr && prev->val > root->val)
        {
            if (first == nullptr)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inOrder(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        inOrder(root);
        if (first != nullptr && second != nullptr)
        {
            swap(first->val, second->val);
        }
    }
};
// @lc code=end
