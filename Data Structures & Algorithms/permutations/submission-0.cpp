class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, curr, nums);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& curr, const vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i: nums) {
            if (find(curr.begin(), curr.end(), i) == curr.end()) {
                curr.push_back(i);
                backtrack(ans, curr, nums);
                curr.pop_back();
            }
        }
    }
};
