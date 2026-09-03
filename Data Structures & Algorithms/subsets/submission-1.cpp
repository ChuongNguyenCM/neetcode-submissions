class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        backtrack(ans, curr, nums, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& curr, const vector<int>& nums, int x) {
        if (x > nums.size()) {
            return;
        }

        ans.push_back(curr);
        for (int i = x; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(ans, curr, nums, i + 1);
            curr.pop_back();
        }
    }
};
