class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, nums)) r = mid - 1;
            else l = mid + 1;
        }
        if (l > nums.size() - 1) return nums[0];

        return nums[l];
    }

    bool check(int mid, vector<int> &nums) {
        return nums[mid] < nums[0];
    }
};
