class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> set(nums.begin(), nums.end());
        int ans = 0;

        for (int i: nums) {
            if (set.count(i - 1)) {
                continue;
            } else {
                int a = 1;
                int x = i + 1;
                while (set.count(x)) {
                    ++x;
                    ++a;
                }
                ans = max(ans,a);
            }
        }

        return ans;
    }
};
