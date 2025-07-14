class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        return helper(0, 0, 0, s1, s2);
    }
    int helper(int p1, int p2, int count, string& s1, string& s2) {
        if (p1 == s1.size() || p2 == s2.size()) {
            return count;
        }
        int match = 0;
        if (s1[p1] == s2[p2]) {
            match = helper(p1 + 1, p2 + 1, count + 1, s1, s2);
        }
        int skip1 = helper(p1 + 1, p2, 0, s1, s2);  // restart count
        int skip2 = helper(p1, p2 + 1, 0, s1, s2);  // restart count
        return max({match, skip1, skip2, count});
    }
};
//TC O(3^(n+m))
//SC O(n+m)
