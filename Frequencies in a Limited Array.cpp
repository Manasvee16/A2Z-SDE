class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        int n = arr.size(); // we need frequencies for 1 to n
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 1 && arr[i] <= n) {
                ans[arr[i] - 1]++; // store at index arr[i]-1
            }
        }
        return ans;
    }
};
