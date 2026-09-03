class Solution {
public:
    void sortColors(vector<int>& nums) {
        int check[3] = {0, 0, 0};
        for (int i: nums) ++check[i];
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (check[j] == 0) ++j;
            nums[i] = j;
            --check[j];
        }
    }
};