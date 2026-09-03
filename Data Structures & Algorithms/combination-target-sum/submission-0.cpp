class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = {};
        vector<int> curr;
        int sum = 0;
        backtrack(ans, curr, sum, nums, target, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& curr, int sum, const vector<int>& nums, int target, int x) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (sum > target) return;

        for (int i = x; i < nums.size(); i++) {
            sum += nums[i];
            curr.push_back(nums[i]);
            backtrack(ans, curr, sum, nums, target, i);
            sum -= nums[i];
            curr.pop_back();
        }
    }
};
