// Each Trie node stores two pointers: one for bit 0 and one for bit 1
struct Node {
    Node* links[2];
    // Initialize both child pointers to nullptr (IMPORTANT to avoid garbage pointers)
    Node() : links{nullptr, nullptr} {}
    // Check if a child for the given bit exists
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
    // Attach a child node at position 'bit' (0 or 1)
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    // Get the child node at position 'bit' (may be nullptr)
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node* root;  // Root of the bitwise trie
public:
    Trie() {
        root = new Node(); // Start with an empty root
    }
    // Insert a non-negative 32-bit integer into the trie
    void insert(int num) {
        Node* node = root;                  // Start from the root
        for (int i = 31; i >= 0; i--) {     // Traverse bits from MSB (31) to LSB (0)
            int bit = (num >> i) & 1;       // Extract the i-th bit of num
            if (!node->containsKey(bit)) {  // If there is no child for this bit
                node->put(bit, new Node()); // Create a new node for this bit
            }
            node = node->get(bit);          // Move to the child for this bit
        }
        // After the loop, the path representing 'num' exists in the trie
    }
    // For a given 'num', compute the maximum XOR value with any number stored in the trie
    // Returns -1 if the trie is empty (no numbers inserted yet)
    int getMax(int num) {
        Node* node = root;                  // Start from the root
        // Quick emptiness check: if both children of root are null, trie has no numbers
        for (int i = 0; i < 2; i++) {
            if (node->get(i)) {
                goto nonEmpty;              // Found at least one child; trie is not empty
            }
        }
        return -1;                          // Empty trie: no candidate to XOR with
    nonEmpty:
        int maxVal = 0;                     // This will accumulate the best XOR value bit by bit
        // Greedy walk: at each bit, prefer taking the opposite bit if available
        for (int i = 31; i >= 0; i--) {     // From MSB to LSB
            int bit = (num >> i) & 1;       // Current bit of 'num'
            if (node->containsKey(1 - bit)) {
                // If there exists a child with the opposite bit, going there sets this XOR bit to 1
                maxVal |= (1 << i);         // Set the i-th bit in the XOR result
                node = node->get(1 - bit);  // Move to the opposite-bit child
            } 
            else {
                // Otherwise, we must go to the same-bit child (this XOR bit becomes 0)
                node = node->get(bit);      // Move to the same-bit child (must exist along inserted paths)
            }
        }
        return maxVal;                      // Best possible XOR value with 'num' from the inserted set
    }
};

class Solution {
public:
    // Returns, for each query [x, m], the maximum XOR of x with any nums[i] such that nums[i] <= m
    // If no such nums[i] exists, the answer is -1 for that query.
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());     // Sort nums to enable incremental insertion by threshold m
        // Prepare offline queries: pair {{x, m}, original_index}
        vector<pair<pair<int, int>, int>> offlineQueries;
        int q = queries.size();
        for (int i = 0; i < q; i++) {
            // Store each query with its original position for later placement in 'result'
            offlineQueries.push_back({{queries[i][0], queries[i][1]}, i});
        }
        // Sort queries by m (threshold) ascending so we can insert eligible nums progressively
        sort(offlineQueries.begin(), offlineQueries.end(),
             [&](auto &a, auto &b) {
                 return a.first.second < b.first.second; // compare by m
             });
        Trie trie;                           // Bitwise trie for storing eligible numbers
        vector<int> result(q);               // Answers in original query order
        int i = 0;                           // Pointer into nums
        int n = nums.size();
        // Process queries in increasing order of m
        for (auto &q : offlineQueries) {
            int x   = q.first.first;         // Query value x
            int m   = q.first.second;        // Threshold m
            int idx = q.second;              // Original index of this query
            // Insert into trie all numbers <= m that we haven't inserted yet
            while (i < n && nums[i] <= m) {
                trie.insert(nums[i]);        // Insert nums[i] into the trie
                i++;                         // Advance to the next number
            }
            // If trie is empty (no nums <= m inserted), getMax returns -1
            result[idx] = trie.getMax(x);    // Compute best XOR with x among inserted numbers
        }
        return result;                       // Return answers in the original order
    }
};

/*
Complexity Analysis:
- Sorting: O(n log n) for nums + O(q log q) for queries.
- Insertion into Trie: Each inserted number costs O(32) = O(1) (fixed bit-length), done up to n times.
- Query getMax: O(32) per query = O(1) (fixed bit-length), done q times.
Total: O(n log n + q log q + n + q) ≈ O(n log n + q log q).
Space: O(n * 32) for the trie in the worst case, plus O(q) for results and query storage.
Notes:
- Assumes non-negative 32-bit integers. For negatives, consider using unsigned ints or consistent bit handling.
- The emptiness check relies on root having at least one non-null child once any number is inserted.
*/
