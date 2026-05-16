/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int idx,
             vector<vector<bool>>& visited)
    {
        int n = board.size();
        int m = board[0].size();

        // Nếu đã tìm hết các ký tự trong word
        if (idx == word.size())
        {
            return true;
        }

        // Nếu đi ra ngoài bảng
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }

        // Nếu ô này đã đi qua rồi
        if (visited[i][j])
        {
            return false;
        }

        // Nếu ký tự hiện tại không khớp
        if (board[i][j] != word[idx])
        {
            return false;
        }

        // Đánh dấu ô này đã đi qua
        visited[i][j] = true;

        // Thử đi 4 hướng
        bool found =
            dfs(board, word, i + 1, j, idx + 1, visited) ||
            dfs(board, word, i - 1, j, idx + 1, visited) ||
            dfs(board, word, i, j + 1, idx + 1, visited) ||
            dfs(board, word, i, j - 1, idx + 1, visited);

        // Backtracking: bỏ đánh dấu để đường đi khác còn dùng được ô này
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(board, word, i, j, 0, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

