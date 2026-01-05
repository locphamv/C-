/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        long long x = 0, y = 0;
        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'U')
            {
                y++;
            }
            if (moves[i] == 'D')
            {
                y--;
            }
            if (moves[i] == 'L')
            {
                x--;
            }
            if (moves[i] == 'R')
            {
                x++;
            }
        }
        if (x == 0 && y == 0)
        {
            return true;
        }
        else
            return false;
    }
};
// @lc code=end
