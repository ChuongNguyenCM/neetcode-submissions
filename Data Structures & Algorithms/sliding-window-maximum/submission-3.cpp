class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1, 0);

        deque <int> q;
        q.push_back(nums[0]);
        int l = 0;

        for (int i = 1; i < k; ++i) {
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        ans[0] = q.front();

        for (int i = k; i < nums.size(); ++i) {
            if (nums[l] == q.front()) q.pop_front();
            while (!q.empty() && q.back() < nums[i]) {
                q.pop_back();
            }

            ++l;
            q.push_back(nums[i]);   
            ans[i - k + 1] = q.front();
        }

        return ans;

    }
};
