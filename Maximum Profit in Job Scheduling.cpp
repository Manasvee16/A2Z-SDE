class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> data(profit.size(), vector<int> (3, -1)); // Step 1: Create a 2D array 'data' of size n x 3, where each row stores {startTime[i], endTime[i], profit[i]} for job i.
        // Step 2: Fill 'data' with the job information.
        for(int i = 0; i < profit.size(); i++) {
            data[i][0] = startTime[i]; // store start time of job i
            data[i][1] = endTime[i];   // store end time of job i
            data[i][2] = profit[i];    // store profit of job i
        }
        sort(data.begin(), data.end(), comp); // Step 3: Sort jobs by their end time (so we can apply DP later). Sorting ensures that when we process jobs sequentially, we already know the best profit achievable for all jobs that end earlier.
        vector<int> temp(data.size()); // Step 4: 'temp[i]' will store the maximum profit we can achieve by considering jobs up to index 'i'.
        temp[0] = data[0][2]; // Base case: If we take only the first job, profit = profit of first job
        int ans = temp[0]; // store global maximum answer
        // Step 5: Process jobs one by one
        for (int i = 1; i < data.size(); i++) {
            int temp2 = data[i][2]; // Option 1: Take the current job's profit alone
            // Step 6: Find the last non-conflicting job (backward search). If job[j] ends before job[i] starts, we can take both.
            for (int j = i - 1; j >= 0; j--) {
                if (data[j][1] <= data[i][0]) {
                    // If job[j] does not overlap, add its best profit.
                    temp2 += temp[j];
                    break; // stop after finding the nearest compatible job
                }
            }
            // Step 7: DP relation
            // temp[i] = max of: Profit without taking current job → temp[i-1] or Profit including current job + best previous non-conflicting job → temp2
            temp[i] = max(temp[i - 1], temp2);
            ans = max(ans, temp[i]);  // Update global maximum
        }
        return ans; // Step 8: Return final maximum profit
    }
    // Comparator to sort jobs by end time
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[1] < b[1]);
    }
};
//TC O(N^2)
//SC O(N)
