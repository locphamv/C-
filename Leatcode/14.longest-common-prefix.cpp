/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string pref = strs[0];
        int prefLen = pref.size();
        for (int i = 0; i < strs.size(); i++)
        {
            while (prefLen > strs[i].size() || pref.substr(0, prefLen) != strs[i].substr(0, prefLen))
            {
                prefLen--;
            }
        }
        return pref.substr(0, prefLen);
    }
};
// @lc code=end
