class MyStack {
    vector<int> ans; // Internal container to store elements of the stack
  public:
    void push(int x) {
        ans.push_back(x); // Insert the element at the end of the vector
    }
    int pop() {
        if (ans.empty())
        {
            // Return -1 as per problem convention (stack underflow) (also pushes -1 into the stack)
            ans.push_back(-1);  
            return -1;
        }
        else
        {
            int num = ans[ans.size() - 1];  // Get the last inserted element (top of the stack)
            ans.pop_back();  // Remove the last element (pop from stack)
            return num; // Return the popped element
        }
    }
};
//TC O(1)
//SC O(N)
