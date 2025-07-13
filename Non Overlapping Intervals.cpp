class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // Sort by end time
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) 
            return 0;
        sort(intervals.begin(), intervals.end(), compare); // Using static comparator
        int count = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                // Overlapping interval → must remove it
                count++;
            } 
            else {
                // No overlap → keep it and update prevEnd
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};
