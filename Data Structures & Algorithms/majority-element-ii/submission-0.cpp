class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size() / 3;
        vector<int> ans = {};

        unordered_map<int, int> mp;
        for (int i: nums) {
            mp[i]++;
            if (mp[i] > n && !st.count(i)) {
                ans.push_back(i);
                st.insert(i);
            }
        }

        return ans;
    }
};