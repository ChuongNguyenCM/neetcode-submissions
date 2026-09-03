class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;

        vector<int> check(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    check[i] = max(check[j] + 1, check[i]);
                    ans = max(ans, check[i]);
                }
            }
        }

        return ans;
    }
};
