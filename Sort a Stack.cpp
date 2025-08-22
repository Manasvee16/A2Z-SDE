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
