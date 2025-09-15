class Solution {
public:
    vector<string> validStrings(int n) {
        // Generate all binary strings of length n. No two consecutive '0's allowed.
        set<string> result;
        string current = ""; // Temporary string used to build binary strings during recursion.
        generate(n, current, '1', result); // Start recursion assuming the "previous character" was '1'. This allows placing either '0' or '1' at first position.
        generate(n, current, '0', result);  // Start recursion assuming the "previous character" was '0'. This ensures both possibilities are explored from the start.
        vector<string> ans; // Final answer container.
        for (auto it: result)
        {
            ans.push_back(it); // Copy all valid strings from set to vector (for return).
        }
        return ans;
    }
    // Recursive helper to generate binary strings.
    void generate(int n, string &current, char lastChar, set<string> &result) {
        if (current.size() == n) {      
            // Base case: if the string is of length n → store it.
            result.insert(current);
            return;
        }
        if (lastChar == '0') {           
            // Rule: If the last character was '0', we cannot place another '0' (to avoid consecutive zeros). So we can only add '1'.
            current.push_back('1');     // Choose '1'
            generate(n, current, '1', result); // Recurse with lastChar = '1'
            current.pop_back();         // Backtrack to remove last choice
        } 
        else {                         
            // Case: If the last character was '1', we are free to add either '0' or '1'.
            current.push_back('0');     // Choose '0'
            generate(n, current, '0', result); // Recurse with lastChar = '0'
            current.pop_back();         // Backtrack
            current.push_back('1');     // Choose '1'
            generate(n, current, '1', result); // Recurse with lastChar = '1'
            current.pop_back();         // Backtrack
        }
    }
};
