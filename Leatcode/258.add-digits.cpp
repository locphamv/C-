/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        int sum = num;
        while (num > 9)
        {
            sum = (num / 10) + (num % 10);
            num = sum;
        }
        return sum;
    }
};
// @lc code=end
