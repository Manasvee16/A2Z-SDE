class Solution {
  public:
    int largest(vector<int> &arr) {
        stack<int> st;
        // Push all elements to the stack
        for (int num : arr) {
            st.push(num);
        }
        // Initialize max with the top of the stack
        int maxVal = st.top();
        st.pop();
        // Pop elements and find the maximum
        while (!st.empty()) {
            maxVal = max(maxVal, st.top());
            st.pop();
        }
        return maxVal;
    }
};
