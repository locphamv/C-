/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
class Solution {
public:
    TreeNode* prev = nullptr;

    bool inOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (!inOrder(root->left))
        {
            return false;
        }

        if (prev != nullptr && root->val <= prev->val)
        {
            return false;
        }

        prev = root;

        if (!inOrder(root->right))
        {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }
};
// @lc code=end

