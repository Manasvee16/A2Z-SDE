class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        // Step 2: Build the result
        string result = "";
        // Keep track of which characters have been added
        while (!freq.empty()) {
            char max_char = 0;
            int max_freq = 0;
            // Step 3: Find character with max frequency
            for (auto entry : freq) {
                if (entry.second > max_freq) {
                    max_freq = entry.second;
                    max_char = entry.first;
                }
            }
            // Step 4: Append max_char max_freq times to result
            result += string(max_freq, max_char);
            // Step 5: Remove from map
            freq.erase(max_char);
        }
        return result;
    }
};
