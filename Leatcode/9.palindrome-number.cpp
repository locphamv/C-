/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        long long reverse = 0;
        int xcopy = x;
        while (x > 0)
        {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }
        if (reverse != xcopy)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
