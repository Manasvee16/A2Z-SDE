void MyQueue ::push(int x) {
    arr[rear] = x; // Place the element 'x' at the current rear position
    rear++; // Move rear pointer to the next empty position
}
int MyQueue ::pop() {
    if (front == rear) // queue is empty 
        return -1;  
    else {  
        int temp = arr[front]; // Store the element at the front of the queue  
        front++; // Move front pointer to the next element   
        return temp; // Return the element that was removed
    }
}
