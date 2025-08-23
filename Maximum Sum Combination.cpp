class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end(), greater<int>()); // Sort both arrays in descending order so the largest elements come first.
        sort(b.begin(), b.end(), greater<int>()); // This makes (a[0] + b[0]) the maximum possible pair sum.
        priority_queue<pair<int, pair<int, int>>> maxheap; // Max-heap storing: {pair_sum, {i, j}} meaning sum = a[i] + b[j]. priority_queue defaults to a max-heap for std::pair (lexicographic by .first, then .second).
        vector<int> ans; // Answer list to collect the top-k sums (not the pairs themselves).
        set<pair<int, int>> visited; // keeps track of index pairs (i, j) we have already pushed to the heap, preventing duplicates and an explosion of identical states.
        // Start from the best possible pair (0,0) if arrays are non-empty. Assumes a and b are not empty; otherwise a[0]/b[0] would be invalid.
        maxheap.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});
        // Extract the best available sum k times (or until the heap runs out).
        while (k-- && !maxheap.empty())
        {
            int sum = maxheap.top().first; // Get the largest sum currently available.
            auto [i, j] = maxheap.top().second; // Retrieve the indices (i, j) that produced this sum.
            maxheap.pop(); // Remove it from the heap.            
            ans.push_back(sum); // Record the sum into the result list.
            // Generate the next two candidate neighbors in the (i, j) grid: (i+1, j) and (i, j+1). Because arrays are sorted descending, these are the next most promising pairs related to (i, j). Push them if in-bounds and not already visited.
            if (i + 1 < (int)a.size() && visited.find({i + 1, j}) == visited.end()) {
                maxheap.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            if (j + 1 < (int)b.size() && visited.find({i, j + 1}) == visited.end()) {
                maxheap.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        return ans; // Return the top-k sums collected.
    }
};
//TC: O(n log n + m log m + k log k)
//SC O(k)
