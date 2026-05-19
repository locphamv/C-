/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool bfs(TreeNode* p, TreeNode* q){
        queue<TreeNode*> tree1;
        queue<TreeNode*> tree2;
        tree1.push(p);
        tree2.push(q);
        while(!tree1.empty() && !tree2.empty())
        {
            TreeNode* a=tree1.front();
            TreeNode* b= tree2.front();
            tree1.pop();
            tree2.pop();

            if(a==nullptr && b != nullptr )
            {
                return false;
            }
             if(a!=nullptr && b == nullptr )
            {
                return false;
            }

            if(a!=nullptr && b!= nullptr)
            
                {  if (a->val!=  b->val){
                return false;
                }

                tree1.push(a->left);
            
                tree1.push(a->right);
          
                tree2.push(b->left);
          
                tree2.push(b->right);
            }
        }
        return true;
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        return bfs(p,q);
    }
};
// @lc code=end

