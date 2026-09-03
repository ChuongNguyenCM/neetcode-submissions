class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> check(m, vector(n, false));
        vector<vector<int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.emplace(0, i);
                check[0][i] = true;
            }
            if (board[m - 1][i] == 'O') {
                q.emplace(m - 1, i);
                check[m - 1][i] = true;
            }
        }

        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') {
                q.emplace(i, 0);
                check[i][0] = true;
            }
            if (board[i][n - 1] == 'O') {
                q.emplace(i, n - 1);
                check[i][n - 1] = true;
            }
        }

        while (!q.empty()) {
            int a = q.size();

            for (int i = 0; i < a; i++) {
                auto p = q.front(); q.pop();

                for (auto v: dr) {
                    int x = p.first + v[0], y = p.second + v[1];

                    if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1 && board[x][y] == 'O' && !check[x][y]) {
                        check[x][y] = true;
                        q.emplace(x, y);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !check[i][j]) board[i][j] = 'X';
            }
        }
    }
};
