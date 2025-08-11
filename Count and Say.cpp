class Solution {
public:
    string countAndSay(int n) {
        string result = "1"; // first sequence
        for (int step = 2; step <= n; step++) {
            string next = "";
            int count = 1;
            for (int i = 0; i < result.size(); i++) {
                // count consecutive same characters
                while (i + 1 < result.size() && result[i] == result[i + 1]) {
                    count++;
                    i++;
                }
                // append count + digit
                next += to_string(count) + result[i];
                count = 1; // reset count for next char group
            }
            result = next; // update sequence
        }
        return result;
    }
};
//TC: O(Ln) where Ln is length of nth sequence
//SC: O(Ln) (two strings at most in memory)

class Solution {
public:
    string countAndSay(int n) {
        string ans="";
        ans=helper(n); //to compute the nth sequence.
        return ans;
    }
string rle(string input)
    {
        string ans="";
        int i=0, count=1;
        for( i=0;i<input.size();i++)
        {
            char start=input[i]; //holds the current character being counted
            count=1; //resets to 1 for the current group.
            while (start==input[i+1])
            {
                count++;
                i++;
            }
            ans+=to_string(count); //append the count followed by the character to the result string.
            ans+=start;
        }
        return ans;
    }
    string helper(int n)
    {
        if (n==1)
            return "1"; //the first term of the sequence.
        return rle(helper(n-1));
      //helper(n-1) recursively calls the same function but for the previous number.
      //then using rle() we apply run-length encoding to it using backtracking.
    }
};
