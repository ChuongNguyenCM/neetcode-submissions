class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];

        for (int i: nums) {
            curSum = max(0, curSum);
            curSum += i;
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
