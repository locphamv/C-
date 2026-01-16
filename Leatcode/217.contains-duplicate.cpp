/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (seen.count(x) > 0)
                return true;
            seen.insert(x);
        }
        return false;
    }
};
// @lc code=end
