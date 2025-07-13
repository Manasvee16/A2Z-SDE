class Solution {
public:
    bool checkValidString(string s) {
        int low = 0; //minimum unmatched '(' → assume all '*' are ')'
        int high = 0; //maximum unmatched '(' → assume all '*' are '('
        for (char c : s) {
            if (c == '(') { //increases the number of unmatched opening brackets.
                low++;
                high++;
            } 
            else if (c == ')') { //tries to close a previous '('. So it decreases the number of unmatched '('.
                low--;
                high--;
            } 
            else { // '*'
                low--; // worst-case: what if we turn '*' into a ')'?
                high++; // best-case: what if we turn '*' into a '('?
            }
            if (high < 0) // too many ')'
                return false;
            if (low < 0) //Even if we tried our best to treat all '*' as ')', we’ve closed more than we opened — which is invalid.
                low = 0; // '*' can help as empty
        }
        return low == 0; // must be balanced
    }
};
