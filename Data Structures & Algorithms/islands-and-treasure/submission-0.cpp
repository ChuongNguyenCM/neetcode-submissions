class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> dr = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i, j, 0}); 
            }
        }

        while (!q.empty()) {
            int a = q.size();

            for (int i = 0; i < a; i++) {
                auto p = q.front();
                q.pop();
                for (auto v: dr) {
                    int x = p[0] + v[0];
                    int y = p[1] + v[1];
                    int z = p[2] + 1;
                    if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1) {
                        if (grid[x][y] != INT_MAX) continue;
                        else {
                            grid[x][y] = z;
                            q.push({x, y, z});
                        }
                    }
                }
            }
        }
    }
};
