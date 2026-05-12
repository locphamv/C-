/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> seen;
        ListNode*p=headA;
        while(p)
        {
            seen.insert(p);
            p=p->next;
        }
        ListNode*q=headB;
        while(q)
        {
            if(seen.count(q))
            {
                return q;
            }
            q=q->next;
        }
        return nullptr;
    }
};
// @lc code=end

