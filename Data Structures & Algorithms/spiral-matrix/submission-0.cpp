class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l = 0;
        int r = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while (l <= r && top <= bottom) {
            // Traverse top row
            for (int i = l; i <= r; i++)
                ans.push_back(matrix[top][i]);

            // Traverse right column
            for (int i = top + 1; i <= bottom; i++)
                ans.push_back(matrix[i][r]);

            // Traverse bottom row (if not same as top)
            if (top < bottom) {
                for (int i = r - 1; i >= l; i--)
                    ans.push_back(matrix[bottom][i]);
            }

            // Traverse left column (if not same as right)
            if (l < r) {
                for (int i = bottom - 1; i > top; i--)
                    ans.push_back(matrix[i][l]);
            }

            l++;
            r--;
            top++;
            bottom--;
        }

        return ans;
    }
};
