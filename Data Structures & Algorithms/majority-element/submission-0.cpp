class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> mp;
        for (int i: nums) {
            mp[i]++;
            if (mp[i] > n) return i;
        }
    }
};