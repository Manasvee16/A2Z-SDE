class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;  // pointers for version1 and version2 strings
        int n = version1.size(), m = version2.size(); // lengths of the two version strings
        // Continue while either string still has components to parse
        while (i < n || j < m) {
            long num1 = 0, num2 = 0;  // numeric value of current component from each version
            // We use long to reduce risk of overflow if a component has many digits. (Using long long is also fine; typical problem constraints keep components small.)
            // parse number from version1 until '.' or end
            while (i < n && version1[i] != '.') {
                // build the integer digit-by-digit
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // If current char is '.', skip it so next loop reads the next component
            if (i < n && version1[i] == '.') 
                i++;
            // parse number from version2 until '.' or end
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (j < m && version2[j] == '.') 
                j++;
            // After parsing corresponding components, compare them immediately. This handles different-length version strings and leading zeros naturally.
            if (num1 < num2) 
                return -1; // version1 is smaller
            if (num1 > num2) 
                return 1;  // version1 is larger
            // if equal, loop continues to compare next components
        }
        // All corresponding components are equal (including implicit trailing zeros) 
        return 0;
    }
};
