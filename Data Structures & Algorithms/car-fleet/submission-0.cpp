class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> check(n);

        for (int i = 0; i < n; i++) {
            check[i] = {position[i], speed[i]};
        }

        sort(check.rbegin(), check.rend());

        double x = double (target - check[0].first) / check[0].second;
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (x >= double (target - check[i].first) / check[i].second) continue;
            else {
                ans++;
                x = double (target - check[i].first) / check[i].second;
            }
        }

        return ans;
    }
};
