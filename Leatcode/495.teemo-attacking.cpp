/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int res = 0;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            if (i == timeSeries.size() - 1)
            {
                res += duration;
            }
            else if (timeSeries[i + 1] - timeSeries[i] >= duration)
            {
                res += duration;
            }
            else
            {
                int a = (timeSeries[i + 1] - timeSeries[i]);
                res += a;
            }
        }
        return res;
    }
};
// @lc code=end
