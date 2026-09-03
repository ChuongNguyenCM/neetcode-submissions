class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % k) return false;

        sort(nums.rbegin(), nums.rend());
        vector<int> check(k, 0);

        return dfs(nums, check, sum / k, 0);
    }

    bool dfs(vector<int>& nums, vector<int>& check, int x, int idx) {
        if (idx == nums.size()) return true;

        for (int i = 0; i < check.size(); i++) {
            if (check[i] + nums[idx] <= x) {
                check[i] += nums[idx];
                if(dfs(nums, check, x, idx + 1)) return true;
                check[i] -= nums[idx];
            }

            if (check[i] == 0) break;
        }

        return false;
    }
};