class Solution {
public:
    int n;
    int ans = 0;

    int totalNQueens(int n) {
        this->n = n;

        unordered_set<int> col;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(0, col, diag1, diag2);

        return ans;
    }

    void backtrack(int x,  unordered_set<int>& col, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (x == n) {
            ++ans;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col.count(i) || diag1.count(x + i) || diag2.count(x - i)) continue;
            col.insert(i);
            diag1.insert(x + i);
            diag2.insert(x - i);
            backtrack(x + 1, col, diag1, diag2);
            col.erase(i);
            diag1.erase(x + i);
            diag2.erase(x - i);
        }
    }
};