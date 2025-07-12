class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, "", ans);
        return ans;
    }
    // idx: current index in num
    // prev: previous operand (for multiplication)
    // curr: current evaluated value
    // path: current expression string
    // ans: final result vector
    void helper(string& num, int target, int idx, long long curr, long long prev, string path, vector<string>& ans) {
        if (idx == num.size()) 
        {
            if (curr == target)
                ans.push_back(path);
            return;
        }
        for (int i = idx; i < num.size(); i++) 
        { 
          // Try forming numbers of different lengths
            // Avoid numbers with leading zeroes
            if (i != idx && num[idx] == '0') //ensures you're not just looking at a single digit '0'
                break;
            string str = num.substr(idx, i - idx + 1);
            long long val = stoll(str);
            if (idx == 0) {
              //If this is the first number in the expression, You can't put + or - or * in front. Just start the path with the number.
                helper(num, target, i + 1, val, val, str, ans); //curr = val, prev = val, path = str
            } 
            else {
                // Try addition
              /*curr + val: update the running total
              prev = val: the last operand is now this val
              Append +val to the path*/
                helper(num, target, i + 1, curr + val, val, path + "+" + str, ans);
                // Try subtraction
                helper(num, target, i + 1, curr - val, -val, path + "-" + str, ans);
                // Try multiplication
              //We remove the last addition, Then add the correct multiplication
                helper(num, target, i + 1, curr - prev + (prev * val), prev * val, path + "*" + str, ans);
            }
        }
    }
};
//TC: O(4^n)
//SC:	O(n) (recursion + expression string)
