class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;  // This will store the total number of substrings that contain at least one 'a', 'b', and 'c'
        for (int i = 0; i < s.size(); i++) { // Outer loop: choose each index `i` as the starting point of a substring
            vector<int> freq(3, 0);  // Frequency array to count occurrences of 'a', 'b', and 'c'
            // freq[0] → count of 'a'
            // freq[1] → count of 'b'
            // freq[2] → count of 'c'
            int right = i; // `right` pointer expands the substring from starting index `i`
            while (right < s.size()) { // Inner loop: keep extending substring until the end of string
                if (s[right] == 'a')
                    freq[0]++;  // Increase count of 'a'
                if (s[right] == 'b')
                    freq[1]++;  // Increase count of 'b'
                if (s[right] == 'c')
                    freq[2]++;  // Increase count of 'c'
                // Check if current substring (i..right) has at least one 'a', 'b', and 'c'
                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
                    count++;  // Valid substring found → increment answer
                right++;  
                // Move right pointer to extend substring
            }
        }
        return count; // Return total number of valid substrings
    }
};
//TC O(N^2)
//SC O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);      // freq[0]=#'a', freq[1]=#'b', freq[2]=#'c' in current window
        int count = 0, left = 0;     // count = answer; left = left pointer of sliding window
        // i is the right pointer of the sliding window
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;      // include s[i] into the window and update its frequency
            // While the current window [left..i] contains at least one 'a','b','c'
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // All substrings starting at 'left' and ending at any position from i to n-1 are valid.
                // Why? Extending to the right won’t remove any character, so the window still has all 3.
                // Number of such substrings is (n - i).
                count += (s.size() - i);
                // Now shrink the window from the left to find the next start that still has all 3.
                freq[s[left] - 'a']--;  // remove s[left] from the window
                left++; // move left boundary rightward
            }
        }
        return count; // total substrings containing at least one 'a','b','c'
    }
};
//TC O(N)
//SC O(1)
