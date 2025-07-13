class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());  // Sort by shortest job first
        long long totalWaitingTime = 0;
        long long currentTime = 0;
        for (int i = 0; i < n; i++) {
            totalWaitingTime += currentTime;
            currentTime += bt[i]; // Time taken so far
        }
        return totalWaitingTime / n;  // Floor division gives required result
    }
};
