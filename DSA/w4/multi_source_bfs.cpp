// MULTI SOURCE BFS:
//queue chứ cặp toạ độ 
// đưa các source vào trước gắn count= 0
// 2 mảng dx dy và 4 vòng for để xét 4 hướng (0=<row<m && 0<=col<n)
// gặp x cần tìm thì gắn count= count trước đó +1 và đưa vào queue chờ xét 4 hướng.

#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void multiBfs(vector<vector<int>> &arr, int m, int n)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        int row = curr.first;
        int col = curr.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_row = row + dx[i];
            int next_col = col + dy[i];
            if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n)
            {
                if (arr[next_row][next_col] == 2147483647)
                {
                    arr[next_row][next_col] = arr[row][col] + 1;
                    q.push({next_row, next_col});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    multiBfs(arr, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}