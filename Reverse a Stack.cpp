class Solution {
  public:
    // Recursive function to reverse the stack
    void reverse(stack<int> &St) {
        if (St.empty()) 
            return;
        int top = St.top();              
        St.pop();
        reverse(St);  // Recursively reverse remaining stack
        insertAtBottom(St, top); // Push current top at the bottom     
    }
    // Helper function to insert an element at the bottom of a stack
    void insertAtBottom(stack<int> &St, int x) {
        if (St.empty()) { // Base case: if empty, just push
            St.push(x);
            return;
        }
        int top = St.top(); // Otherwise, pop the top
        St.pop();
        insertAtBottom(St, x); // Recurse to reach bottom
        St.push(top); // Push back the popped element
    }
};
//TC O(N^2)
//SC O(N)
