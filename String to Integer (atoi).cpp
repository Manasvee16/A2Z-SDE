class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        long long num = 0; //will hold no.
        int sign = 1; //will track if its +ve or -ve
        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;
        // Step 2: Check sign and set it
        if (i < n && (s[i] == '+' || s[i] == '-')) 
        {
            if (s[i]=='-')
                sign=-1;
            else
                sign=1;
            i++;
        }
        // Step 3: Convert digits to number
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0'); //Shifts the current number left by one decimal place and Adds the new digit at the end
            // Step 4: Handle overflow
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;
            i++;
        }
        return (int)(num * sign);
    }
};

class Solution {
public:
    // Recursive function to skip whitespaces
    int skipSpaces(string &s, int i) {
        if (i < s.size() && s[i] == ' ')
            return skipSpaces(s, i + 1); // keep skipping
        return i; // return first non-space index
    }
    // Recursive function to convert digits into number
    long long buildNumber(string &s, int i, int sign, long long num) {
        // base case: if out of bounds or not a digit -> stop
        if (i >= s.size() || !isdigit(s[i]))
            return num * sign;
        // step: add digit
        num = num * 10 + (s[i] - '0');
        // overflow handling
        if (sign == 1 && num > INT_MAX) 
            return INT_MAX;
        if (sign == -1 && -num < INT_MIN) 
            return INT_MIN;
        // recursive call with next character
        return buildNumber(s, i + 1, sign, num);
    }
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        // Step 1: skip spaces using recursion
        i = skipSpaces(s, i);
        // Step 2: check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // Step 3: build number using recursion
        long long num = buildNumber(s, i, sign, 0);
        return (int)num;
    }
};
