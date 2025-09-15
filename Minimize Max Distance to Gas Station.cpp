class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // This function tries to minimize the maximum distance between gas stations after adding K more stations in between the existing ones.
        if (stations.size() < 2) 
            return 0.00; // If there are fewer than 2 stations, there’s no gap to minimize. So, return 0.00 as no extra station placement makes sense.
        priority_queue<pair<double, int>> gaps; // max-heap {gap length, index}
        // to always pick the LARGEST current gap (because placing a station in the largest gap reduces the maximum distance best).
        vector<int> count(stations.size(), 1); // 'count[i]' represents how many sub-gaps the original gap (stations[i+1]-stations[i]) has been divided into. Initially, each gap is undivided → count = 1.
        // Step 1: Push all initial gaps into the heap
        for (int i = 0; i < stations.size() - 1; i++) {
            gaps.push({stations[i+1] - stations[i], i});
        }
        // Step 2: Place K stations one by one
        while (K--) {
            double gap = gaps.top().first;   // Current largest gap
            int idx = gaps.top().second;     // Index of that gap
            gaps.pop();                      // Remove it from heap for processing
            count[idx]++;  // Place one new station in this gap → increases sub-division count
            double newgap = (stations[idx+1] - stations[idx]) * 1.0 / count[idx]; // After placing one more station, the gap is split into smaller equal sub-gaps. New max sub-gap size = (original gap length) / (number of divisions)
            gaps.push({newgap, idx}); // Push updated gap back into the heap so we can re-consider it in future.
            }
        return gaps.top().first; // After all K stations placed, the largest gap in heap = minimized maximum distance
    }
};
