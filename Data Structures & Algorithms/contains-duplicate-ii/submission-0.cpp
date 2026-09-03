class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set <int> set;
        set.insert(nums[0]);
        int l = 0;
        for (int r = 1; r < nums.size(); ++r) {
            if (abs(r - l) > k) {
                set.erase(nums[l]);
                ++l;
            }

            if (set.count(nums[r])) {
                return true;
            }

            set.insert(nums[r]);
        }

        return false;
    }
};