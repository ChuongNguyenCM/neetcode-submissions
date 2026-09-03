class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        target = (long long) target;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1, r = n - 1;

                while (l < r) {
                    if (((long long) nums[i] + (long long) nums[j] + (long long) nums[l] + (long long) nums[r]) < target) {
                        ++l;
                    } else if (((long long) nums[i] + (long long) nums[j] + (long long) nums[l] + (long long) nums[r]) > target) {
                        --r;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                        --r;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    }
                }
            }
        }

        return ans;
    }
};