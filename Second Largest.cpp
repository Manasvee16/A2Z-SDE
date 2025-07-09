class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        if (arr.size() < 2) 
            return -1; // No second largest exists
        stack<int> stack1, stack2;
        for (int num : arr) {
            if (stack1.empty()) {
                stack1.push(num); // First element becomes the largest
            }
            else if (num > stack1.top()) {
                // Current number becomes new largest
                if (!stack2.empty() && stack1.top() > stack2.top()) {
                    stack2.pop(); // Replace second largest if needed
                }
                stack2.push(stack1.top()); // Move current largest to second
                stack1.pop();
                stack1.push(num); // New largest
            }
            else if (num < stack1.top()) {
                if (stack2.empty() || num > stack2.top()) {
                    stack2.push(num); // Update second largest
                }
            }
        }
        if (stack2.empty()) 
            return -1;
        return stack2.top();
    }
};
