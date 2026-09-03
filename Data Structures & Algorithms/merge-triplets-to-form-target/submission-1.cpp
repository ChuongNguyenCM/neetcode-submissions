class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int count = 0;
        vector<bool> check(3, false);
        for (vector<int>& i: triplets) {
            if (i[0] > target[0] || i[1] > target[1] || i[2] > target[2]) {
                continue;
            } 

            if (!check[0] && i[0] == target[0]) {
                check[0] = true;
                ++count;
            }

            if (!check[1] && i[1] == target[1]) {
                check[1] = true;
                ++count;
            }

            if (!check[2] && i[2] == target[2]) {
                check[2] = true;
                ++count;
            }
        }

        return count == 3;
    }
};
