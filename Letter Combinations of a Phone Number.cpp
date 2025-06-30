class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        queue<string> q;
        q.push(""); // Start with empty prefix
        for (int i = 0; i < digits.size(); i++) {
            string letters = getLetters(digits[i]); //Get the possible letters for the current digit
            int size = q.size(); //Number of strings currently in the queue. We process only current-level strings to expand them
            while (size--) { //For each current prefix in the queue, remove it, and expand it with the new letters
                string prefix = q.front();
                q.pop();
                for (int j = 0; j < letters.size(); j++) {
                    q.push(prefix + letters[j]); //Append each letter to the prefix and push it back into the queue
                }
            }
        }
        // Collect results from queue
        vector<string> result; //After processing all digits, the queue contains all combinations
        while (!q.empty()) {
            result.push_back(q.front()); 
            q.pop();
        }
        return result;
    }
    string getLetters(char digit) {
        if (digit == '2') 
            return "abc";
        else if (digit == '3') 
            return "def";
        else if (digit == '4') 
            return "ghi";
        else if (digit == '5') 
            return "jkl";
        else if (digit == '6') 
            return "mno";
        else if (digit == '7') 
            return "pqrs";
        else if (digit == '8') 
            return "tuv";
        else if (digit == '9') 
            return "wxyz";
        else 
            return ""; // For safety
    }
};
/* 
TC O(4^n × n)
n = digits.size()
Each digit can map to 3 or 4 letters
SC O(4^n × n)
Output vector will hold O(4^n) strings, each of length n
*/
