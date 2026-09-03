class Solution {
public:
    int n;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;
        vector<string> curr(n, string(n, '.'));
        backtrack(0, col, diag1, diag2, curr);
        return ans;
    }

    void backtrack(int x, unordered_set<int>& col, unordered_set<int>& diag1, unordered_set<int>& diag2, vector<string>& curr) {
        if (x == n) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col.count(i) || diag1.count(x + i) || diag2.count(x - i)) continue;
            curr[x][i] = 'Q';
            col.insert(i);
            diag1.insert(x + i);
            diag2.insert(x - i);
            backtrack(x + 1, col, diag1, diag2, curr);
            curr[x][i] = '.';
            col.erase(i);
            diag1.erase(x + i);
            diag2.erase(x - i);
        }
    }
};
