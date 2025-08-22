class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> freq;  // Hash map to count frequency of all characters in the string
        int count=0; // Count how many distinct characters exist in the entire string
        for (int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        // For each unique character found in freq, increment count
        for (auto i:freq)
        {
            count++;
        }
        if (count<k) // If total distinct characters < k, no valid substring exists
            return -1;
        int left=0, lengt=0; // left = window start, lengt = longest valid substring length
        unordered_map<char, int> distinct; // stores frequency of characters inside current window
        // Expand the window using "right" pointer
        for (int right=left;right<s.size();right++)
        {
            distinct[s[right]]++;  // Add current character into the map
            while (distinct.size()>k)  // If window contains more than k distinct chars, shrink from left
            {
                distinct[s[left]]--;     // reduce frequency of leftmost character
                if (distinct[s[left]]==0) // if freq becomes 0, remove it from map
                    distinct.erase(s[left]);
                left++; // move window start forward
            }
            // If window contains exactly k distinct chars, update max length
            if (distinct.size()==k)
                lengt=max(lengt, right-left+1);
        }
        return lengt; // Return the maximum length found
    }
};
//TC O(N)
//SC O(1)
