class TrieNode {
public:
    TrieNode* children[26];
    TrieNode(char lett) {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
int countDistinctSubstring(string word) {
    int count = 1; // Start with 1 for the empty substring
    TrieNode* root = new TrieNode('0');
    for (int i = 0; i < word.size(); i++) {
        TrieNode* temp = root;
        for (int j = i; j < word.size(); j++) {
            int idx = word[j] - 'a';
            if (temp->children[idx] == nullptr) {
                temp->children[idx] = new TrieNode(word[j]);
                count++; //this means a new substring was found.
            }
            temp = temp->children[idx];
        }
    }
    return count;
}
