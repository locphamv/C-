/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*p= head;
      std:: unordered_set<ListNode*> list;
        while(p!=nullptr)
        {
            if (list.count(p)) 
            {
                return true;
            }
            list.insert(p);
            p=p->next;
        }
        return false;
    }
};
// @lc code=end

