class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size(); // Get array length
        vector<int> ans(n, 0); // ans[k-1] will hold the "maximum of minimums" for window size k.
        vector<int> window(n, 0);  // window[i] will store the length of the largest window for which arr[i] is the minimum.
        stack<int> values; // Monotonic stack of indices. The stack will keep indices of elements in strictly increasing order of their array values (because we pop on >=).
        // Traverse the array to find "next smaller element to the right" for popped indices.
        for (int i = 0; i < n; i++)
        {
            // While current element is smaller or equal to the element indexed by stack top, the element at stack top cannot extend beyond i as the minimum.
            while (!values.empty() && arr[values.top()] >= arr[i])
            {
                int topp = values.top(); // topp is an index whose next smaller element to the right is i.
                values.pop();
                // If there is still something on stack, values.top() is the previous smaller index. So the window length where arr[topp] is minimum = (rightIndex - leftIndex - 1).
                if (!values.empty())
                    window[topp] = i - values.top() - 1;
                else
                    // If stack empty, there is no previous smaller element, so window stretches from 0 to i-1 -> length = i
                    window[topp] = i;
            }
            values.push(i); // Push current index to stack for future comparisons.
        }
        // After the loop, indices remaining in the stack do not have a next smaller element to the right. Their next smaller is implicitly "beyond the array", so use n as the right bound.
        while (!values.empty())
        {
            int topp = values.top();
            values.pop();
            if (!values.empty())
                // previous smaller is values.top(); window stretches from values.top()+1 .. n-1
                window[topp] = n - values.top() - 1;
            else
                // no previous smaller and no next smaller -> whole array: length = n
                window[topp] = n;
        }

        // Now we have, for every index i:
        // window[i] = length of the largest subarray in which arr[i] is the minimum. We map that length to ans index: length k -> ans[k-1].
        for (int i = 0; i < n; i++)
        {
            int temp = window[i] - 1;         // convert length -> 0-based index
            ans[temp] = max(ans[temp], arr[i]); // for window size = window[i], candidate min = arr[i]
        }
        // Some window sizes may not have been filled; also the result must be non-increasing when moving from smaller windows to larger windows. So propagate maxima leftwards.
        // IMPORTANT: loop starts at n-2 and uses ans[i+1] — this avoids accessing ans[n] (OOB).
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans;
    }
};
/*Use a monotonic stack to compute for each index i the previous smaller and next smaller positions in one pass. From those you get the maximum window length where arr[i] is the minimum.
For each index i we record arr[i] as a candidate for window size window[i].
Finally we ensure ans is monotonic (non-increasing) by pushing each value leftwards so every smaller window gets at least the value of larger windows if applicable.
*/
//TC O(N)
//SC O(N)
