class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> map;
        map[nums[0]] = 1;
        int ans = 0;

        if (nums[0] == k) ans += 1;

        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
            if (nums[i] == k) ans += 1;
            if (map.count(nums[i] - k)) ans += map[nums[i] - k];
            map[nums[i]] += 1;
        }

        return ans;
    }
};