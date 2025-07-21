class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        // Loop over each window starting index
        for (int i = 0; i <= arr.size() - k; i++) 
        {
            set<int> windowSet;  // Will store distinct elements
            // Traverse the current window of size k
            for (int j = i; j < i + k; j++) 
            {
                windowSet.insert(arr[j]); // Automatically removes duplicates
            }
            result.push_back(windowSet.size());  // Count of distinct elements
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result; // To store the result of distinct counts in each window
        unordered_map<int, int> freq; // Frequency map to track occurrences of elements in the current window
        // Initialize the first window of size 'k'
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++; // Add element to frequency map or increment its count
        }
        result.push_back(freq.size()); // Store the count of distinct elements in the first window
        // Slide the window from index 'k' to the end of the array
        for (int i = k; i < arr.size(); i++) {
            freq[arr[i]]++; // Add the new element (entering the window) to the map
            freq[arr[i - k]]--; // Decrease frequency of the element that is going out of the window
            if (freq[arr[i - k]] == 0) // If frequency becomes zero, remove it from map
                freq.erase(arr[i - k]);
            result.push_back(freq.size()); // Store the count of distinct elements for the current window
        }
        return result;
    }
};
