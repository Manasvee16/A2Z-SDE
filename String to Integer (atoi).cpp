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
