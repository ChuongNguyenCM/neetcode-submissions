class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);
        int l = 0;
        int r = numbers.size() - 1;

        while (r > l) {
            if (numbers[r] + numbers[l] > target) {
                --r;
            } else if (numbers[r] + numbers[l] < target) {
                ++l;
            } else {
                ans[0] = l + 1;
                ans[1] = r + 1;
                break;
            }

        }
        return ans;
    }
};
