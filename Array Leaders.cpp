class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        int maxFromRight = INT_MIN;
        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] >= maxFromRight) {
                result.push_back(arr[i]);
                maxFromRight = arr[i];
            }
        }
        // The leaders are collected in reverse order, so reverse the result
        reverse(result.begin(), result.end());
        return result;
    }
};


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
