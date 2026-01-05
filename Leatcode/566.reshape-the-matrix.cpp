/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        if (m == 0)
        {
            return mat;
        }
        int n = mat[0].size();
        if (m * n != r * c)
        {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < m * n; i++)
        {
            res[i / c][i % c] = mat[i / n][i % n];
        }

        return res;
    }
};

// @lc code=end
