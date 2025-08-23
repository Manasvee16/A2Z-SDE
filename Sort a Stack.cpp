void SortedStack ::sort() {
    stack<int> order;  //will hold elements in sorted order.
    // Step 1: Process all elements of 's'
    while (!s.empty())  
    {
        int num = s.top();  // Take the top element from original stack
        s.pop();            // Remove it from 's'
        // Step 2: Ensure that 'order' remains sorted (in increasing order from top to bottom)
        while (!order.empty() && order.top() > num)  
        {
            s.push(order.top());  // Push back larger elements to 's'
            order.pop();          // Remove them from 'order'
        }
        // Step 3: Place 'num' in correct position in 'order'
        order.push(num);  
    }
    // Step 4: At this point, 'order' contains elements in sorted order
    // Printing all elements from top to bottom
    while (!order.empty())  
    {
        cout << order.top() << " ";  // Print top element
        order.pop();                 // Remove it
    }
}
//TC O(N^2)
//SC O(N)

//Inserts an element x into the already sorted stack in its correct position.
void insertSorted(stack<int> &st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

// Recursively sorts the stack by removing one element, sorting the rest, then putting the element back in sorted order.
void SortedStack::sort() {
    if (s.empty()) 
        return;
    int x = s.top();
    s.pop();
    sort();  // sort the remaining stack
    insertSorted(s, x);  // insert current element at correct position
}
//TC O(n) (for recursion in sort) × O(n) (for insertSorted) = O(n^2)
//SC O(n) for recursion
