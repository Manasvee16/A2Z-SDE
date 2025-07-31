class TrieNode { 
public:
    TrieNode* children[26];   // Each node has 26 possible children (a to z)
    char letter;              // The character this node represents
    bool isWord;              // Marks if this node ends a valid word
    TrieNode(char lett) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Initialize all children to null
        }
        letter = lett;       // Store the letter for debugging/tracking (optional)
        isWord = false;      // Initially, this node doesn't mark the end of a word
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode('0');  // Create a root node with dummy character '0'
    string longestValidWord(vector<string>& words) {
        string ans = "";
        sort(words.begin(), words.end()); // Sort for lexicographical order
        for (int i = 0; i < words.size(); i++) {
            if (insert(words[i])) { // If word can be built prefix by prefix
                if (ans.size() + 1 == words[i].size()) {
                    ans = words[i];  // Update longest word found
                }
            }
        }
        return ans;
    }
    bool insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'] == nullptr) {
                TrieNode* node = new TrieNode(word[i]);
                temp->children[word[i] - 'a'] = node;
            }
            temp = temp->children[word[i] - 'a'];
            // All prefixes except the last must already be valid words
            if (i < word.size() - 1 && !temp->isWord)
                return false;
        }
        return temp->isWord = true; // Mark final node as end of a valid word
    }
};
