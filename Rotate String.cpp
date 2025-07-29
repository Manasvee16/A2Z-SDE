class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) 
            return false;
        for (int i = 0; i < s.length(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());  // left rotate by 1
            if (s == goal) 
                return true;
        }
        return false;
    }
};
