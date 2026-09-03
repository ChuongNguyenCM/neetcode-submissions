class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        vector<int> check = {};
        backtrack(n, k, 1, check);
        return ans;
    }

    void backtrack(int n, int k, int x, vector<int>& check) {
        if (check.size() == k) {
            ans.push_back(check);
            return;
        }
        
        for (int i = x; i <= n; i++) {
            check.push_back(i);
            backtrack(n, k, i + 1, check);
            check.pop_back();
        }
    }
};