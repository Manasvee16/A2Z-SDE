class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        // 1. Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // 2. Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]); //We take the earliest start between the existing newInterval and the overlapping intervals[i]
            newInterval[1] = max(newInterval[1], intervals[i][1]); //We take the latest end between the two
            i++;
        }
        ans.push_back(newInterval); // insert the merged newInterval
        // 3. Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
