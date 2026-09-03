class Solution {
public:
    int ans = 0;

    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, int i, int check) {
        if (i == (int)nums.size()) {
            ans += check;          // cộng ở lá
            return;
        }

        // không chọn nums[i]
        backtrack(nums, i + 1, check);

        // chọn nums[i]
        backtrack(nums, i + 1, check ^ nums[i]);
    }
};