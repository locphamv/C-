/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {

            vector<int> &lastInterval = result.back();

            int lastEnd = lastInterval[1];
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if (lastEnd >= currentStart)
            {

                lastInterval[1] = max(lastEnd, currentEnd);
            }
            else
            {

                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
// @lc code=end
