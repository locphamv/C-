/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int j = 0;
        while (target >= nums[j])
        {
            if (target == nums[j])
            {
                return j;
            }
            j++;
            if (j == nums.size())
            {
                break;
            }
        }
        return j;
    }
};
// @lc code=end
