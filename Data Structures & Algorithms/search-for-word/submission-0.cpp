class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        m = (int)board.size();
        n = (int)board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    char save = board[i][j];
                    board[i][j] = '#';                 // mark visited
                    if (dfs(board, word, 1, i, j))     // start from next char
                        return true;
                    board[i][j] = save;                // restore
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& b, const string& w, int k, int x, int y) {
        if (k == (int)w.size()) return true;           // matched all chars

        for (const auto& d : dir) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (b[nx][ny] != w[k]) continue;

            char save = b[nx][ny];
            b[nx][ny] = '#';                           // mark
            if (dfs(b, w, k + 1, nx, ny)) return true;
            b[nx][ny] = save;                          // unmark
        }
        return false;
    }
};
