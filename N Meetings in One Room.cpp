class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings;
        // Pushing the pair of finish time and starting time in a vector.
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        // Sorting the vector of meetings by finish time
        sort(meetings.begin(), meetings.end());
        int lastFinishTime = -1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            // If the start time of this meeting is greater than or equal
            // to the finish time of the previously selected meeting,
            // increment the counter and update last.
            if (meetings[i].second > lastFinishTime) {
                res++;
                lastFinishTime = meetings[i].first;
            }
        }
        // Returning the counter.
        return res;
    }
};
