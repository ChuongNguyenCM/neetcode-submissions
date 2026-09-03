class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> lefts(n), rights(n);
        lefts[0] = height[0];
        for (int i = 1; i < n; i++)
            lefts[i] = max(lefts[i-1], height[i]);
        
        rights[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
            rights[i] = max(rights[i+1], height[i]);
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += min(lefts[i], rights[i]) - height[i];
        
        return ans;
    }
};
