class TrieNode {
public:
    TrieNode* children[2]; // 1. Binary Trie: Only two possible children — 0 and 1.
    int digit;             // 2. Not used in logic; could be removed.
    bool isnum;            // 3. Flag to mark if a number ends at this node.

    TrieNode() {
        for(int i=0; i<2; i++) {
            children[i] = nullptr; // 4. Initialize both children to null.
        }
        isnum = false; // 5. Initially, no number ends here.
    }
};
class Solution {
public:
TrieNode* root = new TrieNode(); // 6. Root node of the binary trie.
    int findMaximumXOR(vector<int>& nums) {
        int maxm=0; // 7. To keep track of the maximum XOR found.
        for (int i=0;i<nums.size();i++)
        {
            insert(nums[i]); // 8. Insert every number into the Trie.
        }
        for (int i=0;i<nums.size();i++)
        {
            TrieNode* temp=root; // 9. Start from root for each number.
            string word = bitset<32>(nums[i]).to_string(); // 10. Convert number to 32-bit binary string.
            string res=""; // 11. Will store the binary string of the best possible XOR match.
            for (int i = 0; i < word.size(); i++) {
                int x = word[i] - '0'; // 12. Get current bit (0 or 1) as int.
                int opp = (int)x ^ 1;  // 13. Get opposite bit (0^1 = 1, 1^1 = 0).
                if (temp->children[opp]) {  // 14. If opposite bit exists, go there (to maximize XOR).
                    temp = temp->children[opp];
                    res += (char)(opp + '0'); // 15. Append that bit to res.
                } 
                else {
                temp = temp->children[x]; // 16. Else, go to the same bit.
                res += (char)(x + '0');   // 17. Append same bit to res.
            }
        }
        int xor_val = stoi(res, 0, 2); // 18. Convert the binary string to an integer.
        maxm = max(maxm, xor_val ^ nums[i]); // 19. Compute XOR with original number, update max.
    }
    return maxm; // 20. Return maximum XOR found.
}
    }
    bool isBinary(const std::string& s) {
    return !s.empty() && s.find_first_not_of("01") == std::string::npos;
}
    void insert(int num) {
    TrieNode* temp = root; // 21. Start at root.
    string word = bitset<32>(num).to_string(); // 22. Get 32-bit binary string of number.
        for (int i = 0; i < word.size(); i++) {
        int bit = word[i] - '0'; // 23. Get current bit as int.
        if (temp->children[bit] == nullptr) { // 24. If path doesn't exist, create new node.
            TrieNode* node = new TrieNode();
            temp->children[bit] = node;
        }
        temp = temp->children[bit]; // 25. Move to child node.
    }
    temp->isnum = true; // 26. Mark the end of number.
    }
};
