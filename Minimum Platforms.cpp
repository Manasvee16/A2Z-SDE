class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int platforms = 1;  // current platforms needed
        int maxPlatforms = 1;  // result
        int i = 1, j = 0;
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                // Train arrives before the last departs -> need new platform
                platforms++;
                i++;
            } 
            else {
                // Train departs before next arrives -> free a platform
                platforms--;
                j++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};
