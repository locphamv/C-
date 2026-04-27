#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void multiSourceBFS(vector<vector<int>> &matrix, int m, int n)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_r = r + dx[i];
            int next_c = c + dy[i];

            if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n &&
                matrix[next_r][next_c] == 2147483647)
            {
                matrix[next_r][next_c] = matrix[r][c] + 1;
                q.push({next_r, next_c});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n))
        return 0;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    multiSourceBFS(matrix, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}