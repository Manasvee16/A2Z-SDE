class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Manual bubble sorting by length
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i].size() > words[j].size()) {
                    swap(words[i], words[j]);
                }
            }
        }
        return helper(words, 0, -1);
    }
    int helper(vector<string>& words, int idx, int previdx) {
        if (idx == words.size()) 
            return 0;
        int take = 0;
        bool canTake = false; //true only if words[previdx] is a valid predecessor of words[idx]
        if (previdx == -1) {
            canTake = true;
        } 
        else {
            string& a = words[previdx];
            string& b = words[idx];
          //We check if a can become b by inserting one letter.
            if (b.size() == a.size() + 1) {
                int i = 0, j = 0;
              //Two pointers to match letters of a and b, and a flag to allow skipping one letter.
                bool skipped = false;
                while (i < a.size() && j < b.size()) {
                    if (a[i] == b[j]) {
                        i++;
                        j++;
                    } 
                    else {
                        if (skipped) {
                            skipped = false;
                            break; //// Already skipped once? Can't skip again.
                        }
                        skipped = true;
                        j++;
                    }
                }
                if (i == a.size()) //If we matched all characters of a, b is a valid successor.
                   canTake = true;
            }
        }
        if (canTake) {
            take = 1 + helper(words, idx + 1, idx);
        }
        int notTake = helper(words, idx + 1, previdx);
        return max(take, notTake);
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i].size() > words[j].size()) {
                    swap(words[i], words[j]);
                }
            }
        }
        int n = words.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); 
        /*row: The current index in the words array that we are considering to include or skip in the word chain.
          column: The index of the previous word that was included in the chain.
          We add +1 because previdx can be -1 (meaning no previous word), and we can't index a vector at -1.
          dp[idx][previdx + 1] stores the maximum chain length we can get starting from index idx when the previous word in the chain is at index previdx*/
        return helper(words, 0, -1, dp);
    }
    int helper(vector<string>& words, int idx, int previdx, vector<vector<int>>& dp) {
        if (idx == words.size()) 
            return 0;
        if (dp[idx][previdx + 1] != -1) 
            return dp[idx][previdx + 1];
        int take = 0;
        bool canTake = false;
        if (previdx == -1) {
            canTake = true;
        } 
        else {
            string& a = words[previdx];
            string& b = words[idx];
            if (b.size() == a.size() + 1) {
                int i = 0, j = 0;
                bool skipped = false;
                while (i < a.size() && j < b.size()) {
                    if (a[i] == b[j]) {
                        i++;
                        j++;
                    } 
                    else {
                        if (skipped) {
                            skipped = false;
                            break;
                        }
                        skipped = true;
                        j++;
                    }
                }
                if (i == a.size()) 
                    canTake = true;
            }
        }
        if (canTake) {
            take = 1 + helper(words, idx + 1, idx, dp);
        }
        int notTake = helper(words, idx + 1, previdx, dp);
        return dp[idx][previdx + 1] = max(take, notTake);
    }
};
