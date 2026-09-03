class Solution {
public:
    vector<int> check;
    unordered_map<int, vector<int>> mp;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        check = vector<int>(numCourses);

        for (auto v: prerequisites) {
            mp[v[1]].push_back(v[0]);
        }

        for (auto [k, v]: mp) {
            if (check[k] == 0) {
                check[k] = 1;
                if (!dfs(k)) return false;
                check[k] = 2;
            }
        }
        return true;
    }

    bool dfs(int x) {
        for (int i: mp[x]) {
            if (check[i] == 0) {
                check[i] = 1;
                if (!dfs(i)) return false;
                check[i] = 2;
            } else if (check[i] == 1) return false;
        }
        return true;
    }
};
