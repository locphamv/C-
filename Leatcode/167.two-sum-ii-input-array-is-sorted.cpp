/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            long long sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                break;
            }
            else if (sum > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        // numbers[0] = i + 1;
        // numbers[1] = j + 1;
        // numbers.resize(2);
        return {i + 1, j + 1};
    }
};
// @lc code=end
