class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dr = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;

        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        int ans = -1;
        while (!q.empty()) {
            int a = q.size();
            ans++;

            for (int i = 0; i < a; i++) {
                auto v = q.front(); q.pop();

                for (auto d: dr) {
                    int x = v.first + d[0];
                    int y = v.second + d[1];
                    if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1 && grid[x][y] == 1) {
                        fresh--;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        if (fresh > 0) return -1;
        return max(ans, 0);
    }
};
