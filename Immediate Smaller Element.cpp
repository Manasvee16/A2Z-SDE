class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        stack<int> order;// to hold elements we've seen while scanning from right to left
        // Traverse from rightmost element to leftmost
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (order.empty())
            {
                // If this is the rightmost element, there is no element to its right
                order.push(arr[i]); // Push current element for the next iteration (its left neighbor)
                arr[i] = -1; // No element on right -> immediate smaller doesn't exist
            }
            else
            {
                if (order.top() < arr[i]) // There is at least one element to the right (on the stack top)
                {
                    // If the immediately right element (top of stack) is smaller, set arr[i] to that value
                    int num = order.top();
                    order.push(arr[i]); // Push current for the next iteration
                    arr[i] = num; // Immediate smaller on the right exists (and is the next element)
                }
                else
                {
                    // If the immediate right element is not smaller, set -1 (this code does NOT search further right)
                    order.push(arr[i]);   // Push current for the next iteration
                    arr[i] = -1;          // No immediate smaller (per this implementation)
                }
            }
        }
    }
};
//TC O(N)
//SC O(N)
