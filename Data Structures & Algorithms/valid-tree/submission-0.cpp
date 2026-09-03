class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        unordered_map<int, vector<int>> mp;
        vector<bool> check(n, false);
        queue<int> q;
        for (auto v: edges) {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        q.push(0);
        check[0] = true;
        int m = 1;

        while (!q.empty()) {
            int a = q.size();

            for (int i = 0; i < a; i++) {
                int x = q.front(); q.pop();
                for (int j: mp[x]) {
                    if (check[j]) continue;
                    check[j] = true;
                    m++;
                    q.push(j);
                }
            }
        }

        return m == n;
    }
};
