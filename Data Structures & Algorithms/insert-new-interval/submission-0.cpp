class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i;
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] >= newInterval[0]) break;
            ans.push_back(intervals[i]);
        }
        
        while (i < intervals.size()) {
            if (newInterval[1] < intervals[i][0]) break;
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
