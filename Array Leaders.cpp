class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        stack<int> st;
        vector<int> result;
        int n = arr.size();
        for (int i = n - 1; i >= 0; --i) {
            //start from right and push if it is greater than top
            if (st.empty() || arr[i] >= st.top()) {
                st.push(arr[i]);
            }
        }
        // Now pop stack to get leaders in correct order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
