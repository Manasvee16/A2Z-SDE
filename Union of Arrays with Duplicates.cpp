class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        // Insert all elements of both arrays
        for (int num : a) {
            s.insert(num);
        }
        for (int num : b) {
            s.insert(num);
        }
        // Convert set to vector
        vector<int> result(s.begin(), s.end());
        return result;
    }
};
