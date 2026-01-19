/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int total = 0;
        vector<int> res;
        int k;
        for (int i = 0; i < operations.size(); i++)
        {

            if (operations[i] == "C")
            {
                res.erase(res.begin() + k - 1);
            }
            else if (operations[i] == "D")
            {
                res.push_back(res[k - 1] * 2);
            }
            else if (operations[i] == "+")
            {
                int sum = res[k - 1] + res[k - 2];
                res.push_back(sum);
            }
            else
            {
                res.push_back(stoll(operations[i]));
            }
            k = res.size();
        }

        for (int i = 0; i < k; i++)
        {
            total += res[i];
        }
        return total;
    }
};
// @lc code=end
