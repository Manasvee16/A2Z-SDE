/*Divide the array into sorted and unsorted parts
Take each element from the unsorted part and insert it into the correct position in the sorted part (by shifting larger elements right)*/
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();  
        // Start from the second element (index 1)
        for (int i = 1; i < n; i++) {
            int key = arr[i]; // The current element to be inserted
            int j = i - 1; // Start comparing with the element before it
            // Shift elements of arr[0 to i-1] that are greater than 'key' to one position ahead
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j]; // Shift element to the right
                j--; // Move to the next element on the left
            }
            // Insert the key at its correct sorted position
            arr[j + 1] = key;
        }
    }
};
