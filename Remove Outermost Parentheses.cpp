class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) 
                    result += ch;
              /*If we are already inside another set of parentheses (depth > 0), we add this '(' to the result.
                If depth == 0, this is the outermost '(' of a primitive substring, so we skip it.*/
                depth++;
            } 
            else {
                depth--;
              /*After reducing the depth, if we're still inside another set of parentheses (depth > 0), this ')' is not outermost, so we add it.
                If depth == 0 now, it means this was the closing ')' of the outermost layer, so we skip it.*/
                if (depth > 0) 
                    result += ch;
            }
        }
        return result;
    }
};
