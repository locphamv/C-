/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        long long left = 1, right = x / 2 + 1;
        int ans = 1;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;

            if (sq == x)
                return (int)mid;
            if (sq < x)
            {
                ans = (int)mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
