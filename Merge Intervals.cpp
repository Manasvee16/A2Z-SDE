class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==1)
            return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end()); //Sorts the intervals based on the start time
        ans.push_back(intervals[0]); //Start by pushing the first interval. This acts as the base for future merging.
        for (int i=1;i<intervals.size();i++)
        {
            if (intervals[i][0]<=ans.back()[1])
            { //This accesses the end value ([1]) of the last interval in ans
                ans.back()[1]=max(ans.back()[1], intervals[i][1]); //Extend the end of the last interval in ans to the maximum of its own end and the current interval's end.
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
//TC O(N)
//SC O(N^2)
